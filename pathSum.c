/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool PathSumHelper(struct TreeNode* root, int targetSum, int sum) {
    if (root == NULL)
        return false;
    sum += root->val;
    if(root->left == NULL && root->right == NULL && sum == targetSum)
        return true;
    else if (root->left == NULL && root->right == NULL)
        return false;
    else
    {
        bool r = false, l = false;
        if(root->left != NULL)
            l = PathSumHelper(root->left, targetSum, sum);
        if(root->right != NULL)
            r = PathSumHelper(root->right, targetSum, sum);
        if(r || l)
            return true;
        return false;
    }
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return PathSumHelper(root, targetSum, 0);
}
