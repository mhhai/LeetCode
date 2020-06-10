//ʹ�û�������
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0)
            return 0;
        int n = s.size();
        vector<int> col(26, 0);
        int maxCount = 0;
        //˫ָ��
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < n)
        {
            //cout << left << " " << right << endl;
            col[s[right] - 'A']++;
            maxCount = max(maxCount, col[s[right] - 'A']);
            //��ǰ���ڳ���Ϊright - left + 1�����ݴ��ڳ����봰������Ŀ�����ַ��ĸ�������жϸøô����ǲ��ǿ��Ծ����滻�õ���ظ��ַ�������Ⱦ��Ǵ��ڳ���
            int length = right - left + 1;
            if (length - maxCount <= k)  //��ǰ���ڵĳ��Ⱦ����滻����ظ��ַ��ĳ���
            {
                res = max(res, length);
                right++;
            }
            else  //��ʱ��s[right]һ����������֮ǰmaxCount���ַ�������ô��ڳ��Ȼ��ǻ����ӣ� ͬʱҲ������left��ͷ�Ĵ��ڲ��������ҵ�������滻����ظ��ַ�����˸ô����Ѿ�ʧȥ������
            //���ϣ����һ������
            //�����ڵ�ʱ��left++������һ���µĴ��ڣ�������right����1�Ļ����µĴ��ڵĴ�С���ᳬ��֮ǰ�Ĵ��ڴ�С�����Ҳ�����ø�����ظ��ַ�
            //���right++�������п��ܻ����ظ��ַ����µĴ��ڣ�Ҫ���ø���������ظ��ַ���maxCountһ��Ҫ���ڵ�ǰ��maxCount,���ڲ��У���Ϊ���ڱ���k��ֵ��Ȼ̫С��
            {
                col[s[left] - 'A']--;
                left++;
                right++;
            }
        }
        return res;
    }
};
