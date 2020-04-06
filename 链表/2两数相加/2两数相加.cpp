/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //������֮���ٴ洢�����¿ռ临�ӶȺܸ�
 /*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//����һ���������ڱ����м�ֵ����ʵ���������
		queue<int> Q;
		while(l1 != nullptr || l2 != nullptr)
		{
			int m, n;
			if(l1 == nullptr)
			  m = 0;
			else
			  m = l1->val;
			if(l2 == nullptr)
			  n = 0;
			else
			  n = l2->val;
			Q.push(m + n);
			if(l1!=nullptr)
			{
			  l1 = l1->next;
			}
			if(l2 != nullptr)
			{
			  l2 = l2->next;
			}
		}
		ListNode* head = new ListNode(-1);
		ListNode* result = head;
		head->val = Q.front()%10;
		int m = Q.front() / 10; //��
		Q.pop();
		while(!Q.empty())
		{
			ListNode* pNext = new ListNode(-1);
			head->next = pNext;
			pNext->val = (Q.front() + m) % 10;
			//cout<<Q.front()<<endl;
			//cout << pNext->val<<endl;;
			m = (Q.front() + m) /10;
			head = pNext;
			Q.pop();
		}
		if(m == 1)
		{
		   ListNode* pNext = new ListNode(-1);
		   head->next = pNext;
		   pNext->val = m;
		   Q.pop();
		}
		return result;
	}
};
*/
//�ڶ����޸ģ�����Ҫ���У�������Ҫά��һ��dummy�ƽڵ�
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//����һ��ջ���ڱ����м�ֵ����ʵ���������
		ListNode* head = new ListNode(-1);
		ListNode* result = head;
		int carry = 0;
		while(l1 != nullptr || l2 != nullptr)
		{
			ListNode* pNext = new ListNode(-1);
			head->next = pNext;
			int m, n;
			if(l1 == nullptr)
			  m = 0;
			else
			  m = l1->val;
			if(l2 == nullptr)
			  n = 0;
			else
			  n = l2->val;
			pNext->val = (m + n + carry) % 10;
			cout << pNext->val << endl;
			carry = (m + n + carry) / 10;
			head = pNext;
			if(l1!=nullptr)
			{
			  l1 = l1->next;
			}
			if(l2 != nullptr)
			{
			  l2 = l2->next;
			}
		}
		if(carry == 1)
		{
		   ListNode* pNext = new ListNode(-1);
		   head->next = pNext;
		   pNext->val = carry;
		}
		return result->next;
	}
};
*/
//�������޸ģ���һЩϸ�ڵĵط������Ż�
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//����һ��ջ���ڱ����м�ֵ����ʵ���������
		ListNode* head = new ListNode(-1);
		ListNode* result = head;
		int carry = 0;
		int m = 0;
		int n = 0;
		while (l1 != nullptr || l2 != nullptr)
		{
			ListNode* pNext = new ListNode(-1);
			head->next = pNext;

			m = (l1 == nullptr) ? 0 : l1->val;
			n = (l2 == nullptr) ? 0 : l2->val;
			pNext->val = (m + n + carry) % 10;
			carry = (m + n + carry) / 10;
			head = pNext;
			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;
		}
		if (carry == 1)
		{
			ListNode* pNext = new ListNode(carry);
			head->next = pNext;
		}
		return result->next;
	}
};
*/