//使用滑动窗口
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0)
            return 0;
        int n = s.size();
        vector<int> col(26, 0);
        int maxCount = 0;
        //双指针
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < n)
        {
            //cout << left << " " << right << endl;
            col[s[right] - 'A']++;
            maxCount = max(maxCount, col[s[right] - 'A']);
            //当前窗口长度为right - left + 1，根据窗口长度与窗口内数目最多的字符的个数做差，判断该该窗口是不是可以经过替换得到最长重复字符，最长长度就是窗口长度
            int length = right - left + 1;
            if (length - maxCount <= k)  //当前窗口的长度就是替换后最长重复字符的长度
            {
                res = max(res, length);
                right++;
            }
            else  //此时的s[right]一定不是属于之前maxCount的字符，否则该窗口长度还是会增加； 同时也表明以left开头的窗口不可能再找到更多的替换后最长重复字符，因此该窗口已经失去了意义
            //因此希望换一个窗口
            //换窗口的时候left++，这是一个新的窗口，但是若right不加1的话，新的窗口的大小不会超过之前的窗口大小，因此也不会获得更大的重复字符
            //因此right++，这是有可能获得最长重复字符的新的窗口，要想获得更长的最仓重复字符，maxCount一定要大于当前的maxCount,等于不行，因为等于表明k的值依然太小了
            {
                col[s[left] - 'A']--;
                left++;
                right++;
            }
        }
        return res;
    }
};
