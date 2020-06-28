/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //使用迭代或者递归的方法都行
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1)
            return reverse(head, n - m + 1);
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;

    }

    ListNode* reverse(ListNode* head, int n)  //反转链表的前n个节点
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