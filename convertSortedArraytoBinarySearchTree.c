/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	if (numsSize == 0)
        	return NULL;
	int i = numsSize / 2;
	struct TreeNode *bst = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	bst->val = nums[i];

	bst->left = sortedArrayToBST(nums, i);
	bst->right = sortedArrayToBST(nums + (i + 1), numsSize - (i + 1));

	return bst;
}
