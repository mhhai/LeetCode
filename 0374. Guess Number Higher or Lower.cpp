/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long p = 1;
        long long q = n;
        while (p <= q)
        {
            //cout << p << " " << q <<endl;
            long long mid = (p + q) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)  //要和他的数字进行比较，注意题意
                p = mid + 1;
            else
                q = mid - 1;
        }
        if (p == q + 1)
            return 1;
        else
            return -1;
        return 0;
    }
};