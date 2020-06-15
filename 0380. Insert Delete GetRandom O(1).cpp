//ʹ�ù�ϣ���������
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (mp.find(val) != mp.end())
			return false;
		//�Ȱ�������ַ���ve��
		ve.push_back(val);
		mp[val] = ve.size() - 1;  //value�д�ŵ��������е��±�
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (mp.find(val) == mp.end())
			return false;
		//��������ִ�������ɾ��
		int last = ve.back();
		mp[last] = mp[val];
		ve[mp[val]] = last;
		//���Դ�ʱve.back�����ֵ��±�Ҳ�仯�ˣ������Ҫ����
		ve.pop_back();
		mp.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		//srand((unsigned)time(NULL));
		int index = rand() % ve.size();
		return ve[index];
	}
private:
	unordered_map<int, int> mp;
	vector<int> ve;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */