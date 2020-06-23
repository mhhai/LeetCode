//ʹ��С����
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
//ʹ�õݹ��˼·���������һ������ʾ����ʱ��
//ʹ�úϲ���������Ȼ���ٵݹ���кϲ���˼��
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
        //��������ͷ����������������
        //ListNode* res = new ListNode(-1);
        ListNode* head = lists[0];
        //�ϲ����ǣ��ϲ��������δ�ϲ�������
        for (int i = 1; i < m; ++i)
        {
            head = mergeTwoList(head, lists[i]);
        }
        return head;
    }
    //���õ����ķ����ϲ��������� 
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