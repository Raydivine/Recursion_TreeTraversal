#include "unity.h"
#include "BinaryTree.h"
#include "Traversal.h"
#include "mock_Print.h"
#include "mock_Stack.h"


void setUp(void){}

void tearDown(void){}
/*
		6
	/		\
	*		*
*/
void test_binary_tree(void){
 Node root = {NULL,	NULL,	6};
 Stack stack;
 stackNew_ExpectAndReturn(&stack);

 print_Expect(6);
 stackPop_ExpectAndReturn(&stack, NULL);
 stackDel_Expect(&stack);
 binaryTreeTraveseInOrder(&root);
}

/*
		10
	/		\
	5		*
*/
void test_binary_tree_with_2_nodes_parrent_and_left_child(void){
 Node leftChild = {NULL,	NULL,	5};
 Node root 			= {&leftChild, NULL , 10};
 Stack stack;
 stackNew_ExpectAndReturn(&stack);
 
 stackPush_Expect(&stack,	&root);
 print_Expect(5);
 stackPop_ExpectAndReturn(&stack, &root);
 print_Expect(10);
 stackPop_ExpectAndReturn(&stack, NULL);
 stackDel_Expect(&stack);
 
 binaryTreeTraveseInOrder(&root);
 
}

/*
		8
	/		\
	7		9
*/
void test_binary_tree_with_2_nodes_parrent_and_left_child_and_right_child(void){
 Node leftChild  =  {NULL,	NULL,	7};
 Node rightChild = {NULL,	NULL,	9};
 Node root = {&leftChild, &rightChild , 8};
 Stack stack;
 stackNew_ExpectAndReturn(&stack);
 
 stackPush_Expect(&stack,	&root);
 print_Expect(7);
 stackPop_ExpectAndReturn(&stack, &root);
 print_Expect(8);
 print_Expect(9);
 stackPop_ExpectAndReturn(&stack, NULL);
 stackDel_Expect(&stack);

 binaryTreeTraveseInOrder(&root);
}

/*
		1
	/		\
	*		 2
*/
void test_binary_tree_with_2_nodes_parrent_and_right_child(void){
 Node rightChild = {NULL,	NULL,	2};
 Node root			 = {NULL, &rightChild , 1};
 Stack stack;
 stackNew_ExpectAndReturn(&stack);
 
 print_Expect(1);
 print_Expect(2);
 stackPop_ExpectAndReturn(&stack, NULL);
 stackDel_Expect(&stack);
 
 binaryTreeTraveseInOrder(&root);
}

/*
		 6
	 /	 \
 	 4		*
 /  \
3   5
*/
void xtest_binary_tree_with_2_nodes_parrent_and_left_child_and_left_grandchild(void){
 Node leftChild2  = {NULL,	NULL,	3};
 Node rightChild2 = {NULL,	NULL,	5};
 Node leftChild1  = {&leftChild2,	&rightChild2,	4};
 Node root			  = {&leftChild1, NULL , 6};
 
 Stack stack;
 stackNew_ExpectAndReturn(&stack);
 
 stackPush_Expect(&stack,	&root);
 stackPush_Expect(&stack,	&leftChild1);
 print_Expect(3);
 stackPop_ExpectAndReturn(&stack, &leftChild1);
 print_Expect(4);
 print_Expect(5);
 stackPop_ExpectAndReturn(&stack, &root);
 print_Expect(6);
 stackPop_ExpectAndReturn(&stack, NULL);
 stackDel_Expect(&stack);
 
 binaryTreeTraveseInOrder(&root);
 
}

/*
			 10
		 /		\
		5		  *
	/
 1
*/

void test_printlinear_tree_with_3_left_child(void){
 Node leftChild2 = {.left=NULL,	.right=NULL,	.data=1};
 Node leftChild1 = {.left=&leftChild2, .right=NULL,	.data=5};
 Node root 		   = {.left=&leftChild1, .right=NULL , .data=10};
 

 printLinear(&root);
 
}
