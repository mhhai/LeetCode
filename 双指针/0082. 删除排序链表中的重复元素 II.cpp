/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //核心是pre要指向新出现的元素，否则会出现断裂
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && cur->next)
        {
            //cout << "a: " << cur->val << endl;
            if (cur->val == cur->next->val)
            {
                while (cur && cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};