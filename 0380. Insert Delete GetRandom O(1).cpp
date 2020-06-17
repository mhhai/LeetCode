//使用哈希表做这道题
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (mp.find(val) != mp.end())
			return false;
		//先把这个数字放在ve中
		ve.push_back(val);
		mp[val] = ve.size() - 1;  //value中存放的是数组中的下标
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (mp.find(val) == mp.end())
			return false;
		//把这个数字从数组中删除
		int last = ve.back();
		mp[last] = mp[val];
		ve[mp[val]] = last;
		//可以此时ve.back中数字的下标也变化了，因此需要更改
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