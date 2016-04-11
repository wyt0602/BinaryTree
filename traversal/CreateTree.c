/**
 * @file CreateTree.c
 * @Brief  Create a binary tree
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-08
 */

#include <stdlib.h>
#include <string.h>

#include "Log.h"
#include "CreateTree.h"

static Person *node_buf = NULL;
static TreeNode *tree_buf = NULL;

TreeNode* create_tree(unsigned int node_count)
{
    char *name_suffix = "Fitz";

    node_buf = calloc(node_count, sizeof(Person));
    if (node_buf == NULL){
	ERROR("malloc error!");
	return NULL;
    }

    tree_buf = calloc(node_count, sizeof(TreeNode));
    if (tree_buf == NULL){
	ERROR("malloc error!");
	return NULL;
    }

    unsigned int i = 0;
    while (i < node_count){
	sprintf(node_buf[i].name, "%d", i);
	strcat(node_buf[i].name, name_suffix);
	node_buf[i].number = i;
	tree_buf[i].element = &node_buf[i];
	++i;
    }

    i = 0;
    for (;;){
	if (2*i + 1 < node_count)
	    tree_buf[i].left = &tree_buf[2*i+1];
	else
	    break;

	if (2*i + 2 < node_count)
	    tree_buf[i].right = &tree_buf[2*i+2];
	else
	    break;

	++i;
    }

    return tree_buf;
}


void visit(void *element)
{
    //Person *p = element;
    //INFO("name:%s number:%d\n", p->name, p->number);
}


void clean()
{
    free(node_buf);
    free(tree_buf);
}








