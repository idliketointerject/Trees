#ifndef AVL_H
#define AVL_H

#include "btree.h"

class avl : public btree {
public:
  virtual ~avl() {
    while(root != NULL) erase(root->value);
  }
  bool insert(int x);
  bool contains(int x);
  bool erase(int x);

  bool insert(int x, node* &p);
  bool contains(int x, node* &p);
  bool erase(int x, node* &p);
  void erase_node(node* &p);
  void replace_with_successor(node* &p);
  void replace_with_successor(node* &p, node* &s);

  void ensure_balanced(node* &q);
  void rotate_with_left_child(node* &q);
  void rotate_with_right_child(node* &q);

  void update_height(node* const p);
  int height(const node* const p);
};

#endif

