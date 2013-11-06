#ifndef BST_H
#define BST_H

#include "btree.h"

class bst:public btree {
public:
	virtual ~bst(){ while(root !=NULL) erase(root->value);}
	bool insert(int x);
	bool contains(int x);
	bool erase(int x);

	bool insert(int x, node* &r);
	bool contains(int x, node* &r);
	bool erase(int x, node* &r);
	void erase_node(node* &r);
	void replace_with_successor(node* &r);
	void replace_with_successor(node* &r, node* &s);
};

#endif
