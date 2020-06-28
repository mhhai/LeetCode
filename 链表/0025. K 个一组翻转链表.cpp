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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 0)
            return nullptr;
        ListNode* a = head;
        ListNode* b = head;

        for (int i = 0; i < k; ++i)
        {
            if (b == nullptr)
                return a;
            b = b->next;
        }
        //cout << "a: " << a->val << " " << b->val << endl;

        ListNode* res = reverseK(a, b);
        //原来的a->next是指向nullptr的
        a->next = reverseKGroup(b, k);
        return res;

    }
    //返回的是链表的头节点
    //为什么需要对区间进行反转，而不是(a, k)，因为这样好确定b
    ListNode* reverseK(ListNode* a, ListNode* b) //对[a, b)这个区间的链表进行反转
    {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        //cout << "c: " << cur->next->val << endl;
        //cout << "c: " << cur->next->next->val << endl;
        while (cur != b)
        {
            //cout << "b: " << cur->val << endl;
            ListNode* pNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = pNext;
        }
        return pre;
    }
};