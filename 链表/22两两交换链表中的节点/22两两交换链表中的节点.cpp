/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //使用递归
 /*
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr || head->next == nullptr)
			return head;
		ListNode* pFirst = head;
		ListNode* pSecond = head->next;

		pFirst->next = swapPairs(pSecond->next);
		pSecond->next = pFirst;

		return pSecond;


	}
};
*/
//使用迭代
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dumpy = new ListNode(-1);
		dumpy->next = head;
		ListNode* pPre = dumpy;

		while (head != nullptr && head->next != nullptr)
		{
			ListNode* pFirst = head;
			ListNode* pSecond = head->next;

			pFirst->next = pSecond->next;
			pSecond->next = pFirst;
			pPre->next = pSecond;

			pPre = pFirst;
			head = pFirst->next;
		}
		return dumpy->next;
	}
};