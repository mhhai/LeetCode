class Solution {
public:
	int climbStairs(int n) {
		//这是一个Fibonacii数列
		if (n == 1 || n == 2)
			return n;
		int res = 0;
		int firstNum = 1;
		int secondNum = 2;
		while (n - 2 > 0)
		{
			res = firstNum + secondNum;
			firstNum = secondNum;
			secondNum = res;
			n--;
		}
		return res;
	}
};