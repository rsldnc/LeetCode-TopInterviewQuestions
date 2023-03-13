/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countNodes(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversalHelper(struct TreeNode *root, int *tab, int *index)
{
    if (!root) 
		return;
	inorderTraversalHelper(root->left, tab, index);
	tab[(*index)++] = root->val;
	inorderTraversalHelper(root->right, tab, index);
}

#include <stdlib.h>

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	int size = countNodes(root);
	int *tab = malloc(size * sizeof(int));
	int index = 0;
	inorderTraversalHelper(root, tab, &index);
	*returnSize = size;
	return tab;
}

