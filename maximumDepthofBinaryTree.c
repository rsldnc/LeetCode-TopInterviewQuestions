/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{
	int left_c;
	int right_c;

	if (root)
	{
		left_c = maxDepth(root->left);
		right_c = maxDepth(root->right);
		if (left_c > right_c)
			return 1 + left_c;
		else
			return 1 + right_c;
	}
	else
		return 0;
}
