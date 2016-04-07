/**
 * @file NonRecursion.c
 * @Brief  Traverse the tree by the nonrecursive method
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-07
 */

#include "BinaryTree.h"
#include "Stack.h"

#define STACK_INIT_SIZE 1024


/* --------------------------------------------------------------------------*/
/**
 * @Brief  pre_order Traverse the tree in pre-order
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void pre_order(TreeNode *root, handle visit)
{
    /**
     * empty tree
     */ 
    if (root == NULL)
	return;

    Stack s = STACK_NULL;
    Stack *stack = &s;

    /**
     * initial stack by STACK_INIT_SIZE
     */ 
    int ret;
    ret = stack_new(stack, STACK_INIT_SIZE);
    if (ret != 0)
	return;

    stack_push(stack, root);

    while (!STACK_EMPTY(stack)){
	/**
	 * visit root
	 */ 
	TreeNode *node = stack_pop(stack);
	visit(node->element);

	/**
	 * right first in, last out;so always visit left first
	 */ 
	if (node->right != NULL)
	    stack_push(stack, node->right);
	if (node->left != NULL)
	    stack_push(stack, node->left);
    }

    stack_delete(stack, NULL);
}


/**
 * push all the left node into the stack
 */ 
#define FIND_LEFTMOST(stack,root) {\
    TreeNode *temp = root;\
    while (temp->left){\
	stack_push(stack, temp->left);\
	temp = temp->left;\
    }\
}

/* --------------------------------------------------------------------------*/
/**
 * @Brief  in_order Traverse the tree in in-order
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void in_order(TreeNode *root, handle visit)
{
    if (root == NULL)
	return;

    Stack s = STACK_NULL;
    Stack *stack = &s;

    int ret;
    ret = stack_new(stack, STACK_INIT_SIZE);
    if (ret != 0)
	return;

    stack_push(stack, root);
    FIND_LEFTMOST(stack, root);

    while (!STACK_EMPTY(stack)){
	TreeNode *node = stack_pop(stack);
	visit(node->element);
	/**
	 * only the right and left child is NULL, visit it
	 */ 
	if (node->right != NULL){
	    stack_push(stack, node->right);
	    FIND_LEFTMOST(stack, node->right);
	}
    }

    stack_delete(stack, NULL);
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  post_order Treverse the tree in post-order
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void post_order(TreeNode *root, handle visit)
{
    if (root == NULL)
	return;

    Stack s = STACK_NULL;
    Stack *stack = &s;

    int ret;
    ret = stack_new(stack, STACK_INIT_SIZE);
    if (ret != 0)
	return;

    stack_push(stack, root);
    FIND_LEFTMOST(stack, root);

    while (!STACK_EMPTY(stack)){
	/**
	 * root always last visit
	 */ 
	TreeNode *node = STACK_TOP(stack);
	if (node->right != NULL){
	    stack_push(stack, node->right);
	    FIND_LEFTMOST(stack, node->right);
	}else{
	    node = stack_pop(stack);
	    visit(node->element);
	}
    }

    stack_delete(stack, NULL);
}

