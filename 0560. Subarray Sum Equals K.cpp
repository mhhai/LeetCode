//�߼���ǰ׺�ͣ���Ѱ�Һ�Ϊk��������
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;  //key��ǰ׺�ͣ�value,ǰ׺��Ϊkey�ĸ���
        hash[0] = 1;
        int sum = 0;  //ǰ׺��
        int res = 0;
        int m = nums.size();
        //cout << hash[1] << endl;
        for (int i = 0; i < m; ++i)
        {
            sum += nums[i];  //sum������[0, i]������֮��
            //��ҪѰ��x, ʹ�� sum - x == k
            res += hash[sum - k];  //֮ǰ��ǰ׺���Ѿ���������
            hash[sum]++; //ע������Ӧ����Ҫ+1�ģ�����û��ϵ���о�����
        }
        return res;
    }
};