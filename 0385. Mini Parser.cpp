/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	NestedInteger deserialize(string s) {
		return parse(s);
	}
private:
	int pos = 0;
	NestedInteger parse(string& s)
	{
		if (s[pos] == '[')
			return parseList(s);
		return parseNum(s);
	}
	NestedInteger parseNum(string& s)
	{
		int num = 0;
		int sign = s[pos] == '-' ? -1 : 1;
		if (s[pos] == '+' || s[pos] == '-')
			pos++;
		while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
		{
			num = num * 10 + (s[pos] - '0');
			pos++;
		}
		return NestedInteger(num * sign);
	}
	NestedInteger parseList(string& s)
	{
		NestedInteger ni;
		while (s[pos] != ']')
		{
			pos++;
			if (s[pos] == ']')
				break;
			ni.add(parse(s));
		}
		pos++;
		return ni;
	}
};