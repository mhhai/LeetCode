#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
//O(Nlogn),��Ϊ�����Ҷ�ӽڵ�ĸ߶�Ҫ������logn��
/*
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if(!root)
			return true;
		//��û����һ���жϣ������жϸ��ڵ��ǲ���ƽ��ģ�����������
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

//O(n)���㷨
//�ڼ���߶ȵ�ʱ��ͬʱ�ж�������ǲ���һ��BST
//ÿ���ڵ�ĸ߶�ֻ����һ��
class Solution {
public:
	//�ȼ����������һ��BST����������
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
