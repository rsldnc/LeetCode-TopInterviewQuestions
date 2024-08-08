/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL || p->val != q->val)
        return false; 
    if(checkTree(p->left, q->left) == false)
        return false;
    if(checkTree(p->right, q->right) == false)
        return false;
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return checkTree(p, q);
}