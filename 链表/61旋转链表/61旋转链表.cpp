#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//��һ���汾���ռ临�ӶȽϸ�
//����Ҫ�õ�˫ָ�룬����������ȷ���ˣ���˿���ֱ��ȷ��������n - k��Ԫ��
/*
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//����һ�������õ�������
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
		//����һ������ʵ�ֶ������ָ������û�
		ListNode* pFirst = head;
		ListNode* pSecond = head;
		for (int i = 1; i <= k; ++i)
			pFirst = pFirst->next;
		while (pFirst->next != nullptr)
		{
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}
		//����pSecond����ָ��nullptr�Ľڵ�
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
		//�õ�����ĳ���
		while (pTmp->next)
		{
			n++;
			pTmp = pTmp->next;
		}
		pTmp->next = head; //�γ�һ����
	   //n - k����β�ڵ�����
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