//使用二分搜索
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        int left = 2;
        int right = num / 2;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (mid * mid == num)
                return true;
            else if (mid * mid < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};