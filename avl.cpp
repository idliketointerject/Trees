#include "avl.h"
#include <algorithm>

bool avl::insert(int x) {
  return insert(x, root);
}

bool avl::insert(int x, node* &p) {
  if(p == NULL) {
    p = new struct node(x, 0);
    return true;
  }
//value already in tree
  else if(p->value == x) {
    return false;
  }
  else {
    bool answer;
    if(x < p->value) answer = insert(x, p->left);
    else answer = insert(x, p->right);
    if(answer) {
      ensure_balanced(p);
      update_height(p);
    }
    return answer;
  }
}

bool avl::contains(int x) {
  return contains(x, root);
}

bool avl::contains(int x, node* &p) {
  if(p == NULL) {
    return false;
  }
  else if(p->value == x) {
    return true;
  }
  else {
    bool answer;
    if(x < p->value) answer = contains(x, p->left);
    else answer = contains(x, p->right);
    return answer;
  }
}

bool avl::erase(int x) {
  return erase(x, root);
}

bool avl::erase(int x, node* &p) {
  if(p == NULL) {
    return false;
  }
  else if(p->value == x) {
    erase_node(p);
    return true;
  }
  else {
    bool answer;
    if(x < p->value) answer = erase(x, p->left);
    else answer = erase(x, p->right);
    if(answer) {
      ensure_balanced(p);
      update_height(p);
    }
    return answer;
  }
}

// p CANNOT be NULL
void avl::erase_node(node* &p) {
  if(p->left == NULL && p->right == NULL) {
    delete p;
    p = NULL;
  }
  else if(p->left != NULL && p->right != NULL) {
    replace_with_successor(p);
  }
  else {
    node* child;
    if(p->left != NULL) child = p->left;
    else child = p->right;
    delete p;
    p = child;
  }
}

void avl::replace_with_successor(node* &p) {
  replace_with_successor(p, p->right);
}

void avl::replace_with_successor(node* &p, node* &s) {
  if(s->left == NULL) {
    p->value = s->value;
    p->data = s->data;
    erase_node(s); // never has left child
  }
  else {
    replace_with_successor(p, s->left);
    ensure_balanced(p);
  }
  update_height(p);
}

void avl::ensure_balanced(node* &p) {
if(height(p->left) - height(p->right) == 2) {
	if(height(p->left->left) > height(p->left->right)) {
    		rotate_with_left_child(p);
    	}
	else if(height(p->left->left) < height(p->left->right)) {
    		rotate_with_right_child(p->left);
      		rotate_with_left_child(p);
    	}
  	else {
      		rotate_with_left_child(p);
    	}
}

else if(height(p->right) - height(p->left) == 2) {
    	if(height(p->right->right) > height(p->right->left)) {
      		rotate_with_right_child(p);
    	}
  	else if(height(p->right->right) < height(p->right->left)) {
      		rotate_with_left_child(p->right);
      		rotate_with_right_child(p);
    	}
  	else {
      		rotate_with_right_child(p);
    	}
}

}

void avl::rotate_with_left_child(node* &q) {
  node* p = q->left;
  q->left = p->right;
  p->right = q;
  update_height(q);
  update_height(p);
  q = p;
}

void avl::rotate_with_right_child(node* &q) {
  node* p = q->right;
  q->right = p->left;
  p->left = q;
  update_height(q);
  update_height(p);
  q = p;
}

void avl::update_height(node* const p) {
  p->data = 1 + std::max(height(p->left), height(p->right));
}

int avl::height(const node* const p) {
  if(p == NULL) return -1;
  else return p->data;
}
