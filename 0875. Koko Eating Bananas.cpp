class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int m = piles.size();
        if (H < m)
            return -1;
        int mx = INT_MIN;
        for (int i = 0; i < m; ++i)
            mx = max(mx, piles[i]);
        int left = 1;
        int right = mx;
        //
        while (left < right)
        {
            //cout << left << " " << right << endl;
            int mid = left + (right - left) / 2;
            //cout << mid << endl;
            if (canFinish(piles, mid, H))
            {
                right = mid;
                //cout << "a" << endl;
            }
            else
                left = mid + 1;
        }
        return left;
    }

    bool canFinish(vector<int>& piles, int mid, int H)
    {
        //cout << "mid: " << mid << endl;
        int res = 0;
        int m = piles.size();
        for (int i = 0; i < m; ++i)
        {
            res += time(piles[i], mid);
        }
        //cout << "res" << res << endl;
        return res <= H;
    }

    int time(int n, int speed) //计算速度为speed的时间
    {
        //cout << "n: " << n << " " <<  "speed: " << speed << endl;
        int res = (n / speed) + ((n % speed == 0) ? 0 : 1);
        //cout << "res1: " << res << endl;
        //cout << (n / speed + (n % speed == 0) ? 0 : 1) << endl;
        return res;
    }
};