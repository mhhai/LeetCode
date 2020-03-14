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
		//��intervals��������
		sort(intervals.begin(), intervals.end());
		//��ʼ��save����
		save = intervals[0];
		//������������б���
		for (int i = 1; i <= intervals.size(); ++i)
		{
			//����ǰ����������Ͻ����жϣ��Ծ����Ǻϲ���һ�����仹�ǽ�save�����ӵ�res��
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