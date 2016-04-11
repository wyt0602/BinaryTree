#include <stdio.h>
#include "BinaryTree.h"
#include "CreateTree.h"
#include "Log.h"


#define RESULT_FILE "recursion.txt"
//#define RESULT_FILE "nonrecursion.txt"
//#define RESULT_FILE "breadthfirst.txt"

int main()
{
    TreeNode *root = create_tree(TREE_MAX_SIZE);
    if (root == NULL)
	return -1;
    LOG_FILE_OPEN(RESULT_FILE);

    fprintf(stderr, "pre order!\n");
    fflush(stderr);
    pre_order(root, visit);

    fprintf(stderr, "in order!\n");
    fflush(stderr);
    pre_order(root, visit);

    fprintf(stderr, "post order!\n");
    fflush(stderr);
    pre_order(root, visit);

    LOG_FILE_CLOSE();

    clean();

    return 0;
}
