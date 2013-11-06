#ifndef BTREE_H
#define BTREE_H

#include <cstddef>
//class which handles the printing of inorder and preorder traversals
class btree{

public:
	virtual ~btree(){}
	btree() : root(NULL) {}
	void print();
  	virtual bool insert(int x) = 0;
  	virtual bool contains(int x) = 0;
  	virtual bool erase(int x) = 0;
protected:
	struct node{
		int value;
		int data;
		node* left;
		node* right;
	//ways to construct a node
	node(int value) : value(value), left(NULL), right(NULL) {}
	node(int value, int data) : value(value), data(data), left(NULL), right(NULL) {}
	};
	node* root;
private:
	void print_preorder(node* root);
	void print_inorder(node* root);
};
#endif

