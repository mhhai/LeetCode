class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> col;
        for (int i = 0; i < s.size(); ++i)
            col[s[i]]++;
        vector<int> nums(10, 0);
        nums[0] = col['z'];
        nums[2] = col['w'];
        nums[4] = col['u'];
        nums[6] = col['x'];
        nums[8] = col['g'];
        nums[3] = col['h'] - nums[8];
        nums[5] = col['f'] - nums[4];
        nums[7] = col['s'] - nums[6];
        nums[1] = col['o'] - nums[0] - nums[2] - nums[4];
        nums[9] = col['i'] - nums[8] - nums[6] - nums[5];
        string ret;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < nums[i]; ++j)
                ret += to_string(i);
        }
        return ret;
    }
};