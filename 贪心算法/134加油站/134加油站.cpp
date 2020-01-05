#include<vector>
using namespace std;
//�����ʱ�临�Ӷ���N��ƽ��������Ҫ����жϱ߽�����
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
				//��ǰ��
				//��Ҫ�Ǳ߽���������ôȷ��
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
//Ҫ�뻷��һ�ܣ�gas������ܺͱ������cost������ܺ�
//��total_gas��ʾ���е��ͣ�current_gas��ʾ��ǰ����վ����
//������ʼλ��
//һ������Ҫ�������������Ŀ�н⣬�ý⼴ΪΨһ�⣬���Կ���ֻ��עgas������ܺͱ������cost������ܺ�
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
			//����ʹ��+=����Ϊ��ȷ��ĳһ����ʼλ�ú󣬻���Ҫ����current_gas���жϸ�λ���в���
			//��gas  = [1,2,3,4,5]
			//  cost = [3,4,5,1,2]
			//Ϊ�������ж�i = 3��λ��֮�󣬲���Ҫi = 4��λ�ã���Ϊ����Ψһ��
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