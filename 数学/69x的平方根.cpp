class Solution {
public:
	int mySqrt(int x) {
		if (x < 1)
			return 0;
		double x0 = 100;
		double x1 = (x0 + x / x0) / 2;
		while (abs(x1 - x0) > 0.0001)
		{
			x0 = x1;
			x1 = (x0 + x / x0) / 2;
		}
		cout << x1 << endl;
		return (int)x1;
	}
};