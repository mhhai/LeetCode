/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//µÚÒ»°æ
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> Q;
		TreeNode* p = root;
		Q.push(p);
		int count = 1;
		while (!Q.empty())
		{
			int length = Q.size();
			vector<int> tmp;
			if (count == 0)
			{
				for (int i = 0; i < length; ++i)
				{
					p = Q.front();
					Q.pop();
					tmp.push_back(p->val);
					if (p->left)
						Q.push(p->left);
					if (p->right)
						Q.push(p->right);
					count++;
				}
			}
			else
			{
				for (int i = 0; i < length; ++i)
				{
					p = Q.front();
					Q.pop();
					tmp.push_back(p->val);
					if (p->right)
						Q.push(p->right);
					if (p->left)
						Q.push(p->left);
					count--;
				}
			}
			res.push_back(tmp);
		}
		return res;
	}
};