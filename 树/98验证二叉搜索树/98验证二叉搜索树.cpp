//µÚÒ»°æ 
#include<iostream>
#include<stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	bool helper(TreeNode* node, int lower, int upper) {
		if (node == nullptr) return true;

		int val = node->val;
		if (lower != NULL && val <= lower) return false;
		if (upper != NULL && val >= upper) return false;

		if (!helper(node->right, val, upper)) return false;
		if (!helper(node->left, lower, val)) return false;
		return true;
	}

	bool isValidBST(TreeNode* root) {
		return helper(root, NULL, NULL);
	}
};
/*
class Solution1 {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		//vector<int> res;
		long c = (long)INT_MIN - 1;
		while (1)
		{
			if (root)
			{
				s.push(root);
				root = root->left;
			}
			else {
				if (!s.empty())
				{
					//res.push_back(s.top()->val);
					if (s.top()->val <= c)
					{
						return false;
					}
					c = s.top()->val;
					root = s.top()->right;
					s.pop();

				}
				else
					break;
			}
		}
		/*
		for (int i = 1; i < res.size(); ++i)
		{
			cout << res[i] << endl;
			if (res[i] < res[i - 1])
				return false;
		}
		*/
		//return true;


	//}
//};
//