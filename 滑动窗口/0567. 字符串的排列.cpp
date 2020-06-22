//这道题是想要扩大窗口
//把排列的问题转成哈希表来解决，计算两个字符串之间的汉明距离
//这道题需不需要用到汉明距离
//按照模板的意思，这道题是始终维护一个大小为s1.size()的窗口，对于该窗口，需要在O(1)的时间复杂度内判断其是否是s1的一个排列
//因此需要用到Hamming距离
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s2.size();
        unordered_map<char, int> need, window;
        for (auto ch : s1)
            need[ch]++;
        int left = 0, right = 0;
        int distance = 0;
        while (right < m)
        {
            char ch = s2[right];
            if (need.count(ch))
            {
                window[ch]++;
                if (window[ch] == need[ch])
                    distance++;
            }
            //收缩窗口
            while (right - left + 1 == s1.size())
            {
                //cout << left << " " << right << endl;
                if (distance == need.size())
                    return true;
                if (window.count(s2[left]))
                {
                    //cout << s2[left] << " " << window[s2[left]] << endl;
                    if (window[s2[left]] == need[s2[left]])
                        distance--;
                    window[s2[left]]--;
                }
                left++;
            }
            right++;
        }
        return false;
    }
};