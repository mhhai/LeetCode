class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> window, need;
        for (char ch : t)
            need[ch]++;
        //cout << need.size() << endl;
        //对于s来说的两个指针
        int left = 0;
        int right = 0;
        //表示两个字符串的距离
        int distance = 0;
        int minLength = INT_MAX;
        string res = "";
        while (right < m)
        {
            char ch = s[right];
            //string test = "a";
            //test[0] = ch;
            //cout << test << endl;

            if (need.count(ch))
            {
                window[ch]++;  //即使多了也加
                //cout << test << ": " << window[ch] << endl;
                if (window[ch] == need[ch])
                    distance++;
            }
            //cout << distance << endl;
            //当distance到一定数目后，开始收缩边界
            while (distance == need.size())
            {
                //string temp = "a";
                //temp[0] = s[left];
                //cout << "s[left] " << s[left] << endl;
                //left++;  //无论如何窗口都会加1
                int size = right - left + 1;
                //cout << "left: " << left << " " << "right" << right << endl;
                //cout << size << endl;
                if (need.count(s[left]))
                {
                    //cout << "window.count(s[left]: " << window.count(s[left]) << endl;
                    if (need[s[left]] == window[s[left]])
                        distance--;
                    window[s[left]]--;
                }
                //cout << size << endl;
                if (size < minLength)
                {

                    minLength = min(minLength, size);
                    //cout << minLength << endl;
                    res = s.substr(left, minLength);
                }
                left++;
            }
            right++;
        }
        return res;
    }
};