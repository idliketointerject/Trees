#include "bst.h"


bool bst::insert(int x){
	return insert(x, root);
}

bool bst::insert(int x, node* &r){
	if(r == NULL){
		r = new struct node(x, 0);
		return true;
	}
	else if(r->value == x){
		return false;
	}
	else {
		bool answer;
		if(x<r->value) answer = insert(x,r->left);
		else answer = insert(x,r->right);
		return answer;
	}
}

bool bst::contains(int x){
	return contains(x, root);
}

bool bst::contains(int x, node* &r){
	if(r == NULL)
		return false;
	else if(r->value == x)
		return true;
	else{
		bool answer;
		if(x < r->value) answer = contains(x, r->left);
		else answer = contains(x, r->right);
		return answer;
	}
}

bool bst::erase(int x){
	return erase(x, root);
}

bool bst::erase(int x, node* &r){
	if(r == NULL) return false;
	else if(r->value == x){
		erase_node(r);
		return true;
	}
	else{
		bool answer;
		if(x<r->value) answer = erase(x,r->left);
		else answer = erase(x, r->right);
		return answer;
	}
}

//assume r is not null

void bst::erase_node(node* &r){
	if(r->left == NULL && r->right == NULL){
		delete r;
		r = NULL;
	}
	else if(r->left != NULL && r->right != NULL){
		replace_with_successor(r);
	}
	else{
		node* child;
		if(r->left != NULL)
			child = r->left;
		else
			child = r->right;
		delete r;
		r = child;
	}
}

void bst::replace_with_successor(node* &r){
	replace_with_successor(r, r->right);
}

void bst::replace_with_successor(node* &r, node* &s){
	if(s->left == NULL){
		r->value = s->value;
		erase_node(s);//never has a left child
	}
	else{
		replace_with_successor(r, s->left);
	}
}

