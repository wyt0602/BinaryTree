/**
 * @file Recursion.c
 * @Brief  Traverse the tree by the recursive way
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-07
 */
#include <stdlib.h>

#include "BinaryTree.h"


/* --------------------------------------------------------------------------*/
/**
 * @Brief  pre_order Traverse the tree by the pre-order 
 *
 * @Param root Root of the tree
 * @Param visit The function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void pre_order(TreeNode *root, handle visit)
{
    if (root != NULL){
	visit(root->element);
	pre_order(root->left, visit);
	pre_order(root->right, visit);
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  in_order Traverse the tree by the in-order way
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void in_order(TreeNode *root, handle visit)
{
    if (root != NULL){
	in_order(root->left, visit);
	visit(root->element);
	in_order(root->right, visit);
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  post_order Traverse the tree by the post-order way
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void post_order(TreeNode *root, handle visit)
{
    if (root != NULL){
	post_order(root->left, visit);
	post_order(root->right, visit);
	visit(root->element);
    }
}


