#include<vector>
using namespace std;
//��һ��
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pFirst = nums.size() - 1;
		int pSecond = nums.size() - 2;
		int pThird = nums.size() - 3;
		while (pThird >= 0)
		{
			if (nums[pSecond] != nums[pThird])
			{
				pSecond--;
				pThird--;
			}
			else if (nums[pSecond] == nums[pThird])
			{
				if (nums[pSecond] = nums[pFirst])
				{
					//�ҵ�һ��������nums[pFirst]�������н���
					while (nums[++pThird] == nums[pFirst])
						continue;
					swap(nums[pThird], nums[pSecond + 1]);
					pFirst += 2;
				}
				else {
					while
				}
			}
		}
	}
};
*/
//�ڶ���
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pFirst = nums.size() - 1; //ά�����޸ĺ�����Ŀ�ʼ�±�
		int pSecond = nums.size() - 2; //
		int count = 0;
		while (pSecond >= 0)
		{
			if (nums[pFirst] != nums[pSecond])
			{
				pFirst--;
				pSecond--;
				count++;
			}
			else if (nums[pFirst] == nums[pSecond])
			{
				//ȥѰ��
				int pThird = pSecond;
				while (nums[--pThird] == nums[pSecond] && pThird >= 0)
					continue;
				//ֱ���ҵ�
				//û�ҵ�
				if (pThird == -1)
				{
					count++;
					return count;
				}
				nums[pSecond + 1] = nums[pThird];
				pFirst = pSecond + 1;
				pSecond = pThird;
				count += 2;
			}
		}

	}
};
*/

//������
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int j = 1, count = 1; //count������ʾλ��i��Ԫ�ص���Ŀ
		//��ʾд��λ��
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				count++;
			}
			else //˵���³��ֵ�Ԫ��
			{
				count = 1;
			}

			if (count <= 2)
			{
				nums[j++] = nums[i];
			}
		}
		return j;
	}
};