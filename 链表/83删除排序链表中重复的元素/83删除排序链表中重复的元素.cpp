/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//��һ��
/*
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return head;
		int val = head->val;
		ListNode* pPre = head;
		ListNode* pCur = head->next;
		while (pCur->next)
		{
			if (pCur->val == val)
			{
				//ɾ��
				pPre->next = pCur->next;
			}
			else
			{
				val = pCur->val;
				pPre = pCur;
			}
			pCur = pCur->next;

		}
		if (pCur->val == pPre->val)
			pPre->next = nullptr;

		return head;
	}
};
*/
//�ڶ���
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pCur = head;
		while (pCur != nullptr && pCur->next != nullptr)
		{
			if (pCur->next->val == pCur->val)
			{
				pCur->next = pCur->next->next;
			}
			else {
				pCur = pCur->next;
			}
		}
		return head;
	}
};