#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//第一个版本，空间复杂度较高
//不需要用到双指针，由于链表长度确定了，因此可以直接确定整数第n - k个元素
/*
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//遍历一遍链表，得到链表长度
		if (head == nullptr || k <= 0)
			return head;
		int count = 0;
		ListNode* pp = head;
		while (pp)
		{
			count++;
			pp = pp->next;
		}
		if (k % count == 0)
			return head;
		if (k > count)
			k = k % count;
		//遍历一遍链表实现对链表的指针进行置换
		ListNode* pFirst = head;
		ListNode* pSecond = head;
		for (int i = 1; i <= k; ++i)
			pFirst = pFirst->next;
		while (pFirst->next != nullptr)
		{
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}
		//现在pSecond就是指向nullptr的节点
		ListNode* rHead = pSecond->next;
		pSecond->next = nullptr;
		pFirst->next = head;
		return rHead;
	}
};
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || k <= 0)
			return head;
		int n = 0;
		ListNode* pTmp = new ListNode(-1);
		pTmp->next = head;
		//得到链表的长度
		while (pTmp->next)
		{
			n++;
			pTmp = pTmp->next;
		}
		pTmp->next = head; //形成一个环
	   //n - k正序尾节点的序号
		ListNode* pTail = head;
		for (int i = 1; i < n - k % n; ++i)
		{
			pTail = pTail->next;
		}
		ListNode* pHead = new ListNode(-1);
		pHead = pTail->next;
		pTail->next = nullptr;
		return pHead;
	}
};
int main()
{
	Solution a;
	ListNode* head = new ListNode(1);
	ListNode* head1 = new ListNode(2);
	ListNode* head2 = new ListNode(3);
	ListNode* head3 = new ListNode(4);
	ListNode* head4 = new ListNode(5);
	head->next = head1;
	head1->next = head2;
	head2->next = head3;
	head3->next = head4;
	head4->next = nullptr;
	a.rotateRight(head, 2);
	system("pause");
}