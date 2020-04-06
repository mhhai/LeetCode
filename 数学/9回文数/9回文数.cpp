class Solution {
public:
	bool isPalindrome(int x) {
		//用一个vector来存储这个数
		if (x < 0)
			return false;
		vector<int> v;
		while (x > 0)
		{
			v.push_back(x % 10);
			x = x / 10;
		}
		int i = 0;  //指向数组第一个元素
		int j = v.size() - 1;  //指向数组最后一个元素
		while (i < j)
		{
			if (v[i++] != v[j--])
				return false;
		}
		return true;
	}
};