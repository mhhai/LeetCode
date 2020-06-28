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
        //ԭ����a->next��ָ��nullptr��
        a->next = reverseKGroup(b, k);
        return res;

    }
    //���ص��������ͷ�ڵ�
    //Ϊʲô��Ҫ��������з�ת��������(a, k)����Ϊ������ȷ��b
    ListNode* reverseK(ListNode* a, ListNode* b) //��[a, b)��������������з�ת
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