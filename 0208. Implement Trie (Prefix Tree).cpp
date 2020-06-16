//虽然可以不把节点单独提出来，但是这样更符合习惯
//并不需要真正保留字符，根据vector的下标就可以知道字典
class TrieNode
{
public:
	TrieNode()
	{
		is_end = false;
		next.resize(26);
		for (int i = 0; i < 26; ++i)
		{
			next[i] = nullptr;
		}
	}
	vector<TrieNode*> next;
	bool is_end;

};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		//要先创建一个TrieNode节点作为root，这很重要，第一个字符对应root中vector的下标
		root = new TrieNode();   //这句话必须要有    
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		//每次插入一个单词,root不能被改变
		TrieNode* cur = root;
		int size = word.size();
		int i = 0;
		while (i < size)
		{
			//cout <<word[i] - 'a' <<endl;
			if (cur->next[word[i] - 'a'] == nullptr)
				cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
			i++;
		}
		cur->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		//每次搜索一个单词
		TrieNode* cur = root;  //从root开始搜索
		int size = word.size();
		int i = 0;
		while (i < size)
		{
			if (cur->next[word[i] - 'a'] == nullptr)
				return false;
			cur = cur->next[word[i] - 'a'];
			i++;
		}
		return cur->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		//从root开始搜索这个前缀
		TrieNode* cur = root;
		int i = 0;
		int size = prefix.size();
		while (i < size)
		{
			if (cur->next[prefix[i] - 'a'] == nullptr)
				return false;
			cur = cur->next[prefix[i] - 'a'];
			i++;
		}
		return true;
	}
private:
	TrieNode* root;  //做为一棵树，有一个根节点
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */