/**
 * @file BreadthFirst.c
 * @Brief  Traverse the tree by breadth first
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-07
 */
#include <stdlib.h>

#include "BinaryTree.h"
#include "Queue.h"


/* --------------------------------------------------------------------------*/
/**
 * @Brief  breadth_first Traverse the tree by the breadth first way
 *
 * @Param root Root of the tree
 * @Param visit Function that handles the element
 */
/* ----------------------------------------------------------------------------*/
void breadth_first(TreeNode *root, handle visit)
{
    if (root == NULL)
	return;

    Queue queue = QUEUE_INIT;
    Queue *ptr_queue = &queue;
    queue_in(ptr_queue, root);

    while (!QUEUE_EMPTY(ptr_queue)){
	TreeNode *node = queue_out(ptr_queue);
	visit(node->element);
	if (node->left != NULL)
	    queue_in(ptr_queue, node->left);
	if (node->right != NULL)
	    queue_in(ptr_queue, node->right);
    }

    queue_delete(ptr_queue, NULL);
}

