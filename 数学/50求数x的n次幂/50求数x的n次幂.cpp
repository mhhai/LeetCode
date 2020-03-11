#include<iostream>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (x == 0)
			return 0;
		long ex;
		ex = n > 0 ? n : -n;
		cout << ex << endl;
		double result = power(x, ex);

		return n > 0 ? result : 1 / result;
	}

	double power(double x, unsigned int ex)
	{
		if (ex == 0)
			return 1;
		if (ex == 1)
			return x;
		double result;
		result = power(x, ex / 2);
		result *= result;
		if (ex & 0x01)
			result *= x;
		return result;
	}
};

int main()
{
	Solution a;
	double b = a.myPow(2, -2147483648);
	cout << b << endl;
		system("pause");
}