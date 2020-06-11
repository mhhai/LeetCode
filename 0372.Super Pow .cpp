class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int end = b.back();
        b.pop_back();
        int part1 = myPow(a, end);
        int part2 = myPow(superPow(a, b), 10);
        return part1 * part2 % base;
    }

    int myPow(int a, int k)
    {
        if (k == 0)
            return 1;
        a = a % base;
        int res = 1;
        if (k % 2 == 1)
            return (a * myPow(a, k - 1)) % base;
        else
        {
            int sub = myPow(a, k / 2);
            return (sub * sub) % base;
        }
    }
private:
    int base = 1337;
};