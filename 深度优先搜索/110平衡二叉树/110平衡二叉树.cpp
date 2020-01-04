#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
//O(Nlogn),因为最深的叶子节点的高度要被计算logn次
/*
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if(!root)
			return true;
		//若没有这一句判断，则是判断根节点是不是平衡的，不满足题意
		if(!isBalanced(root->left) || !isBalanced(root->right))
			return false;
		return abs(height(root->left) - height(root->right)) > 1 ? false : true;
	}
	int height(TreeNode* root)
	{
		if(!root)
			return -1;
		return max(height(root->left), height(root->right)) + 1;
	}
};
*/

//O(n)的算法
//在计算高度的时候同时判断这棵树是不是一颗BST
//每个节点的高度只计算一次
class Solution {
public:
	//先假设这棵树是一棵BST树再做决定
	bool balance = true;
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		height(root);
		return balance;
	}
	int height(TreeNode* root)
	{
		if (!root)
			return -1;
		int left_height = height(root->left);
		int right_height = height(root->right);
		if (abs(left_height - right_height) > 1)
		{
			balance = false;
		}
		return max(left_height, right_height) + 1;
	}
};
