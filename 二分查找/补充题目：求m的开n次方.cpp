#include<iostream>

using namespace std;
//ʹ�ö��ַ�
const double expr1 = 10e-14;
double mySqrt(double m, int n)
{
	double left = 0;
	double right = m;
	double ans = 0;
	while (right - left > expr1)
	{
		double mid = left + (right - left) / 2;
		double temp = 1;
		for (int i = 0; i < n; ++i)
		{
			temp *= mid;  //mid��n�η�
		}
		if (temp <= m)  //˵��̫С��
		{
			left = mid;
			ans = mid;
		}
		else
		{
			right = mid;
		}
	}
	return ans;
}
int main()
{
	double res = mySqrt(2, 10);
	cout.precision(13);
	cout << res << endl;
}