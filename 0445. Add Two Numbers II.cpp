//使用两个栈
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while (head1 != nullptr)
        {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2 != nullptr)
        {
            s2.push(head2->val);
            head2 = head2->next;
        }
        int car = 0;
        int ret = 0;
        ListNode* dummy = nullptr;
        while (!s1.empty() || !s2.empty())
        {
            int m = s1.empty() ? 0 : s1.top();
            int n = s2.empty() ? 0 : s2.top();
            int temp = (m + n + car) % 10;
            car = (m + n + car) / 10;
            ListNode* head = new ListNode(temp);
            head->next = dummy;
            dummy = head;
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
        }
        if (car == 1)
        {
            ListNode* head = new ListNode(1);
            head->next = dummy;
            dummy = head;
        }
        return dummy;
    }
};