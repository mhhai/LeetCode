/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int length = Q.size();
            vector<int> temp;
            for (int i = 0; i < length; ++i)
            {
                Node* cur = Q.front();
                temp.push_back(cur->val);
                for (int i = 0; i < cur->children.size(); ++i)
                {
                    Q.push(cur->children[i]);
                }
                Q.pop();
            }
            ret.push_back(temp);
        }
        return ret;
    }
};