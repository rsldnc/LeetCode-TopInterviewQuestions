/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode *root)
{
	if (!root)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversalHelper(struct TreeNode *root, int *tab, int *index)
{
	if (!root)
		return;
	inorderTraversalHelper(root->left, tab, index);
	tab[*index] = root->val;
	(*index)++;
	inorderTraversalHelper(root->right, tab, index);
}

#include <stdlib.h>

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	int size = countNodes(root);
	int *tab = (int *)malloc(size * sizeof(int));
	int index = 0;
	inorderTraversalHelper(root, tab, &index);
	*returnSize = size;
	return tab;
}

bool isSymmetric(struct TreeNode *root)
{
	int size;
	int *tab = inorderTraversal(root, &size);
	int i = 0;
	int j = size - 1;
	while (i < j)
	{
		if (tab[i] == tab[j])
		{
			i++;
			j--;
		}
		else
			return false;
	}
	struct TreeNode *ll = root;
	struct TreeNode *rr = root;
	int lc = 0;
	int rc = 0;
	j = size / 2;
	while (j--)
	{
		if (!ll->left)
		{
			if (ll->right)
				ll = ll->right;
		}
		else
		{
			ll = ll->left;
			lc++;
		}
		if (!rr->right)
		{
			if (rr->left)
				rr = rr->left;
		}
		else
		{
			rr = rr->right;
			rc++;
		}
		if (!(lc == rc))
			return false;
	}
	if (!(lc == rc))
		return false;
	if ((ll && !rr) || (!ll && rr))
		return false;
	if ((!ll && !rr) || (ll && rr && ll->val == rr->val))
		return true;
	else
		return false;
}
