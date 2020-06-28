/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //使用迭代的方法来解决
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur)
        {
            ListNode* pNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pNext;
        }
        return pre;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //使用递归的方法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};