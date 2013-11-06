#include "btree.h"
#include <iostream>

//btree::btree(){
//	root = NULL;
	
//}

void btree::print(){
	print_preorder(root);
	std::cout << std::endl;
	print_inorder(root);
	std::cout << std::endl;
}

void btree::print_preorder(node* root){
	if(root == NULL) return;
	std::cout << root->value << " ";
	print_preorder(root->left);
	print_preorder(root->right);
}

void btree::print_inorder(node* root){
	if(root == NULL) return;
	print_inorder(root->left);
	std::cout << root->value << " ";
	print_inorder(root->right);
}
