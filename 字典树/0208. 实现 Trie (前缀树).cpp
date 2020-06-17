//��Ȼ���Բ��ѽڵ㵥�����������������������ϰ��
//������Ҫ���������ַ�������vector���±�Ϳ���֪���ֵ�
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
		//Ҫ�ȴ���һ��TrieNode�ڵ���Ϊroot�������Ҫ����һ���ַ���Ӧroot��vector���±�
		root = new TrieNode();   //��仰����Ҫ��    
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		//ÿ�β���һ������,root���ܱ��ı�
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
		//ÿ������һ������
		TrieNode* cur = root;  //��root��ʼ����
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
		//��root��ʼ�������ǰ׺
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
	TrieNode* root;  //��Ϊһ��������һ�����ڵ�
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */