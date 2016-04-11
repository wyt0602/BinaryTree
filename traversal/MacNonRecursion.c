/**
 * @file MacNonRecursion.c
 * @Brief  Traverse the tree by the nonrecursive method
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-11
 */
#include <stdlib.h>

#include "BinaryTree.h"

#define STACK_INIT_SIZE 1024

typedef struct Stack{
    /** 
     * stack array's start address
     **/
    void *start_address[STACK_INIT_SIZE];
    /** 
     * stack's size
     **/
    unsigned int size;
    /** 
     * top of the stack
     **/
    unsigned int top;
}Stack;

#define STACK_EMPTY(stack) ((stack->top) == 0)
#define STACK_FULL(stack) ((stack->top) == (stack->size))
#define STACK_TOP(stack) ((stack->start_address)[stack->top-1])

#define STACK_NULL {\
    .start_address = {}, \
    .size = STACK_INIT_SIZE, \
    .top = 0 \
}

#define stack_new(stack,size) 0

#define stack_delete(stack,func) do {\
    stack->top = 0; \
} while (0)

#define stack_push(stack,element) do {\
    stack->start_address[stack->top] = element; \
    stack->top++; \
} while (0)

#define stack_pop(stack) ((stack->top)>0?(stack->start_address[--(stack->top)]):NULL)

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
#define FIND_LEFTMOST(stack, root) do {\
    TreeNode *temp = root;\
    while (temp->left){\
	stack_push(stack, temp->left);\
	temp = temp->left;\
    }\
} while (0)

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

    /**
     * if the right child of the node in the stack is searched, 
     * stack_flag's relative position is set to 1;
     * 0 is the initial state 
     */ 
    int stack_flag[STACK_INIT_SIZE] = {};

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
	if (stack_flag[stack->top-1] == 0 && node->right != NULL){
	    stack_flag[stack->top-1] = 1;
	    stack_push(stack, node->right);
	    FIND_LEFTMOST(stack, node->right);
	}else{
	    stack_flag[stack->top-1] = 0;
	    node = stack_pop(stack);
	    visit(node->element);
	}
    }

    stack_delete(stack, NULL);
}

