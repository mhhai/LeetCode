//需要建一棵字典树
//并且字典树的搜索策略要根据题目的意思进行调整
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
	//插入的是前缀
	void  insert(string& s)
	{
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); ++i)
		{
			if (cur->next[s[i] - 'a'] == nullptr)
				cur->next[s[i] - 'a'] = new TrieNode();
			cur = cur->next[s[i] - 'a'];
		}
		cur->is_end = true;  //is_end单独占一个节点
	}
	//搜索的句子中的单词
	//返回的是单词前缀的索引
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
				return -1;  //表示该字符没有前缀
		}
		return -1;
	}
private:
	TrieNode* root;
};
class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		//建树
		Trie* trieRoot = new Trie();
		for (int i = 0; i < dict.size(); ++i)
			trieRoot->insert(dict[i]);
	}
	//将句子进行分离，得到单词
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