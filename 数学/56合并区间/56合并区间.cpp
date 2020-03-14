#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<int> save;

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1)
			return intervals;
		//对intervals进行排序
		sort(intervals.begin(), intervals.end());
		//初始化save集合
		save = intervals[0];
		//对所有区间进行遍历
		for (int i = 1; i <= intervals.size(); ++i)
		{
			//对最前面的两个集合进行判断，以决定是合并成一个区间还是将save区间扔到res中
			if (i == intervals.size())
			{
				res.push_back(save);
				return res;
			}
			if (save[1] < intervals[i][0])
			{
				res.push_back(save);
				save = intervals[i];
			}
			else
			{
				save[1] = save[1] >= intervals[i][1] ? save[1] : intervals[i][1];
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> a;
	vector<int> b = {1,2};
	vector<int> c = {10,20};
	vector<int> d = {3,6};
	a.push_back(b);
	a.push_back(c);
	a.push_back(d);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[i].size(); ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}