#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		queue<pair<TreeNode*, int>> Q;
		Q.push(make_pair(root, 1));
		int maxDepth = 0;
		while (!Q.empty())
		{
			pair<TreeNode*, int> p = Q.front();
			Q.pop();
			TreeNode* node = p.first;
			int depth = p.second;
			if (!node)
			{
				maxDepth = depth > maxDepth ? depth : maxDepth;
				Q.push(make_pair(node->left, depth + 1));
				Q.push(make_pair(node->right, depth + 1));
			}
		}
		return maxDepth;
	}
};