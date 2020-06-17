//��Ҫ��һ���ֵ���
//�����ֵ�������������Ҫ������Ŀ����˼���е���
struct TrieNode
{
	vector<TrieNode* > next;
	bool is_end;

	TrieNode()
	{
		next.reserve(26);
		for (int i = 0; i < 26; ++i)
			next[i] = nullptr;
		is_end = false;
	}
};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}
	//�������ǰ׺
	void  insert(string& s)
	{
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); ++i)
		{
			if (cur->next[s[i] - 'a'] == nullptr)
				cur->next[s[i] - 'a'] = new TrieNode();
			cur = cur->next[s[i] - 'a'];
		}
		cur->is_end = true;  //is_end����ռһ���ڵ�
	}
	//�����ľ����еĵ���
	//���ص��ǵ���ǰ׺������
	int findIndex(string& word)
	{
		TrieNode* cur = root;
		//if(cur->next[word[0] - ''])
		for (int i = 0; i < word.size(); ++i)
		{
			if (cur->next[word[i] - 'a'] != nullptr && cur->next[word[i] - 'a']->is_end)
				return i;
			else if (cur->next[word[i] - 'a'] != nullptr)
				cur = cur->next[word[i] - 'a'];
			else
				return -1;  //��ʾ���ַ�û��ǰ׺
		}
		return -1;
	}
private:
	TrieNode* root;
};
class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		//����
		Trie* trieRoot = new Trie();
		for (int i = 0; i < dict.size(); ++i)
			trieRoot->insert(dict[i]);
	}
	//�����ӽ��з��룬�õ�����
	vector<string> split(string sentence)
	{
		vector<string> res;
		int i = 0;
		int size = sentence.size();
		while (i < size)
		{
			string temp = "";
			while (sentence[i] != "")
			{
				temp += sentence[i];
				i++;
			}
			res.push_back(temp);
		}
	}
};