#include "BinaryTree.h"
#include <stdio.h>
#include "Print.h"
#include "Stack.h"

void binaryTreeTraveseInOrder(Node *root){
	Stack *stack = stackNew();
	Node *curNode;
	
	curNode = root;
	if(curNode->left){
		stackPush(stack, root);
		print(curNode->left->data);
		stackPop(stack);
	}		
	print(root->data);
	
	if(curNode->right){
		print(curNode->right->data);
	}		
  stackPop(stack);
	stackDel(stack);
}


void printLinear(Node *node){
	if(node!=NULL){
		printLinear(node->left);
		printf("Node: %d\n",node->data);
	}
}