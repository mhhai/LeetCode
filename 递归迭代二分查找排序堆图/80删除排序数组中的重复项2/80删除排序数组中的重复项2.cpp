#include<vector>
using namespace std;
//第一版
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
					//找第一个不等于nums[pFirst]的数进行交换
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
//第二版
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pFirst = nums.size() - 1; //维护的修改后数组的开始下标
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
				//去寻找
				int pThird = pSecond;
				while (nums[--pThird] == nums[pSecond] && pThird >= 0)
					continue;
				//直到找到
				//没找到
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

//第三版
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int j = 1, count = 1; //count用来表示位置i处元素的数目
		//表示写入位置
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				count++;
			}
			else //说明新出现的元素
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