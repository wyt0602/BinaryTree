/**
 * @file CreateTree.h
 * @Brief  Create tree interface
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-08
 */

#ifndef CREATE_TREE_H_
#define CREATE_TREE_H_

#include "BinaryTree.h"

#define TREE_MAX_SIZE 50000

typedef struct Person{
    char name[20];
    int number;
}Person;

TreeNode* create_tree(unsigned int node_count);
void visit(void* element);
void clean();

#endif
