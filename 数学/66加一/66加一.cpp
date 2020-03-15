#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res(digits.size());
		int carry = 0;
		res[digits.size() - 1] = (digits.back() + 1 + carry) % 10;
		carry = (digits.back() + 1 + carry) / 10;
		for (int i = digits.size() - 2; i >= 0; --i)
		{
			res[i] = (digits[i] + carry) % 10;
			carry = (digits[i] + carry) / 10;
		}
		if (carry == 1)
		{
			res.insert(res.begin(), 1);
			return res;
		}
		return res;
	}
};