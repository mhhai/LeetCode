//��һ��
//ʹ���������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    //ʹ���������
    //�������л��㷨����״̬�ģ����Բ��ܶ���һ��string

    string serialize(TreeNode* root) {
        ostringstream out;
        serializeCore(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeCore(in);
    }
private:
    void serializeCore(TreeNode* root, ostringstream& out)
    {
        if (!root)
        {
            out << "#" << " ";  //֮���Լ�һ��" "������Ϊistringstream���� " " Ϊ�ֽ��
            return;
        }
        out << root->val << " ";
        serializeCore(root->left, out);
        serializeCore(root->right, out);
    }
    TreeNode* deserializeCore(istringstream& in)
    {
        string val;
        in >> val;
        //cout << val << endl;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeCore(in);
        root->right = deserializeCore(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));