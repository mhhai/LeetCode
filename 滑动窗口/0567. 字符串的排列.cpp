//���������Ҫ���󴰿�
//�����е�����ת�ɹ�ϣ������������������ַ���֮��ĺ�������
//������費��Ҫ�õ���������
//����ģ�����˼���������ʼ��ά��һ����СΪs1.size()�Ĵ��ڣ����ڸô��ڣ���Ҫ��O(1)��ʱ�临�Ӷ����ж����Ƿ���s1��һ������
//�����Ҫ�õ�Hamming����
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
            //��������
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