/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        int res = countPath(root, sum);
        int a = pathSum(root->left, sum);
        int b = pathSum(root->right, sum);
        return a + b + res;
    }

    int countPath(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return 0;
        sum = sum - root->val;
        int res = sum == 0 ? 1 : 0;
        return res + countPath(root->left, sum) + countPath(root->right, sum);
    }
};