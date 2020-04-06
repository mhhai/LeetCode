/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //计算完之后再存储，导致空间复杂度很高
 /*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//创建一个队列用于保存中间值，并实现逆序输出
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
		int m = Q.front() / 10; //商
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
//第二次修改，不需要队列，但是需要维护一个dummy哑节点
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//创建一个栈用于保存中间值，并实现逆序输出
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
//第三次修改，对一些细节的地方进行优化
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//创建一个栈用于保存中间值，并实现逆序输出
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