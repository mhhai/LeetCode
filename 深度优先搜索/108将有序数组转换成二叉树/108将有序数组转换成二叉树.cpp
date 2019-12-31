#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;
		return arrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* arrayToBST(vector<int>& nums, int p, int q)
	{
		if (p > q)
			return nullptr;
		int i = (p + q) / 2;
		TreeNode* root = new TreeNode(nums[i]);
		//root->val = nums[i];
		root->left = arrayToBST(nums, p, i - 1);
		root->right = arrayToBST(nums, i + 1, q);
		return root;
	}
};
