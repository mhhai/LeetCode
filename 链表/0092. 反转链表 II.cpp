/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //ʹ�õ������ߵݹ�ķ�������
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1)
            return reverse(head, n - m + 1);
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;

    }

    ListNode* reverse(ListNode* head, int n)  //��ת�����ǰn���ڵ�
    {
        if (n == 1)
        {
            succ = head->next;
            return head;
        }

        ListNode* res = reverse(head->next, n - 1);
        head->next->next = head;
        head->next = succ;
        return  res;
    }
private:
    ListNode* succ = nullptr;
};