//滑动窗口 + 在O(1)时间复杂度内判断是否为字母异位词
//这个窗口大小也是固定的。。。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        vector<int> res;
        unordered_map<char, int> need, window;
        for (auto ch : p)
            need[ch]++;
        int left = 0, right = 0;
        int distance = 0;
        while (right < m)
        {
            char ch = s[right];
            if (need.count(ch))
            {
                window[ch]++;
                if (window[ch] == need[ch])
                    distance++;
            }
            while (right - left + 1 == p.size())
            {
                if (distance == need.size())
                    res.push_back(left);
                if (window.count(s[left]))
                {
                    if (window[s[left]] == need[s[left]])
                        distance--;
                    window[s[left]]--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};