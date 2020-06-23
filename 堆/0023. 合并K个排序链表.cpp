//使用小顶堆
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> Q;
        for (auto i : lists)
        {
            if (i)
                Q.push(i);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!Q.empty())
        {
            ListNode* temp = Q.top();
            Q.pop();
            cur->next = temp;
            cur = cur->next;
            if (temp->next)
                Q.push(temp->next);
        }
        cur->next = nullptr;
        return dummy->next;
    }

    struct comp
    {
        bool operator()(ListNode*& a, ListNode*& b)
        {
            return a->val > b->val;
        }
    };
};
//使用递归的思路，但是最后一个测试示例超时了
//使用合并两个链表，然后再递归进行合并的思想
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int m = lists.size();
        if (lists.empty())
            return nullptr;
        //怎样处理开头是两个空链表的情况
        //ListNode* res = new ListNode(-1);
        ListNode* head = lists[0];
        //合并的是：合并后的链表，未合并的链表
        for (int i = 1; i < m; ++i)
        {
            head = mergeTwoList(head, lists[i]);
        }
        return head;
    }
    //采用迭代的方法合并两个链表 
    ListNode* mergeTwoList(ListNode*& a, ListNode*& b)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (a != nullptr && b != nullptr)
        {
            cout << a->val << " " << b->val << endl;
            if (a->val < b->val)
            {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            }
            else
            {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        if (a == nullptr)
            cur->next = b;
        else if (b == nullptr)
            cur->next = a;
        return dummy->next;
    }
};