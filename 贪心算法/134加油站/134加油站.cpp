#include<vector>
using namespace std;
//这里的时间复杂度是N的平方，而且要多次判断边界条件
/*
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		int oil = 0;
		if(N == 1 && gas[0] >= cost[0])
		{
			return 0;
		}
		for(int i = 0; i < gas.size(); ++i)
		{
			if(gas[i] < cost[i])
				continue;
			else
			{
				oil = gas[i];
				//往前走
				//主要是边界条件该怎么确定
				if(i == N - 1)
				{
					oil = oil - cost[N -1] + gas[0];
						if(oil < cost[0])
							break;
						else
						{
							for(int p = 1; p <= i; ++p)
							{
								if(p == i)
									return i;
								oil = oil - cost[p - 1] + gas[p];
								if(oil < cost[p])
									break;
							}
						}
				}
				for(int j = i + 1; j < N; ++j)
				{
					oil = oil - cost[j - 1] + gas[j];
					if(oil < cost[j])
						break;
					if(j == N - 1 && oil >= cost[N - 1])
					{
						if(i == 0)
						{
							return 0;
						}
						oil = oil - cost[N -1] + gas[0];
						if(oil < cost[0])
							break;
						else
						{

							for(int p = 1; p <= i; ++p)
							{
								if(p == i)
									return i;
								oil = oil - cost[p - 1] + gas[p];
								if(oil < cost[p])
									break;

							}
						}
					}
				}
			}
		}
		return -1;

	}
};
*/
//要想环形一周，gas数组的总和必须大于cost数组的总和
//用total_gas表示所有的油，current_gas表示当前加油站的油
//关于起始位置
//一个很重要的条件是如果题目有解，该解即为唯一解，所以可以只关注gas数组的总和必须大于cost数组的总和
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		int total_gas = 0;
		int current_gas = 0;
		int start_position = 0;
		for (int i = 0; i < N; ++i)
		{
			total_gas += gas[i] - cost[i];
			//这里使用+=是因为在确定某一个起始位置后，还需要根据current_gas来判断该位置行不行
			//以gas  = [1,2,3,4,5]
			//  cost = [3,4,5,1,2]
			//为例，在判断i = 3的位置之后，不需要i = 4的位置，因为答案是唯一的
			current_gas += gas[i] - cost[i];
			if (current_gas < 0)
			{
				current_gas = 0;
				start_position = i + 1;
			}
		}
		return total_gas >= 0 ? start_position : -1;
	}
};