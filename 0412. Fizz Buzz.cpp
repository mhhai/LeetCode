class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n, "");
        for (int i = 0; i <= n - 1; ++i)
        {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
                ret[i] = "FizzBuzz";
            else if ((i + 1) % 3 == 0)
                ret[i] = "Fizz";
            else if ((i + 1) % 5 == 0)
                ret[i] = "Buzz";
            else
                ret[i] = to_string(i + 1);
        }
        return ret;
    }
};