/**
 * @file BinaryTree.h
 * @Brief  Binary tree interfaces
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-07
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct TreeNode{
    struct TreeNode *left;
    struct TreeNode *right;
    void *element;
}TreeNode;

typedef void (*handle)(void*);

//traversal
void pre_order(TreeNode *root, handle visit);
void in_order(TreeNode *root, handle visit);
void post_order(TreeNode *root, handle visit);

void breadth_first(TreeNode *root, handle visit);

#endif
