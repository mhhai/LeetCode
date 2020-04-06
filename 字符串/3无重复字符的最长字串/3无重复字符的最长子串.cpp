//������
//����ʱ������
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int ans = 0;
		for(int i = 0; i < n; ++i)
		  for(int j = i; j < n; ++j)
		  {
			  if(UniqueSubString(i, j, s))
			  {
				  ans = max(ans, j - i + 1);
			  }

		  }
		return ans;
	}

	bool UniqueSubString(int i, int j, string s)
	{
		unordered_set<char> set;
		for(int p = i; p <= j; ++p)
		{
			if(!set.count(s.at(p)))
			  set.insert(s.at(p));
			else
			  return false;
		}
		return true;
	}
};
*/
//ʹ�û�������
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int ans = 0;
		int i = 0;
		int j = 0;
		unordered_set<char> set;
		while(i < n && j < n)
		{
			if(!set.count(s.at(j)))
			{
				set.insert(s.at(j));
				ans = max(ans, j - i + 1);
				j++;  //���������ƶ�
			}
			else
				set.erase(s.at(i++));  //i++
		}
		return ans;
	}
};
*/
//ʹ��hashmap
//�������õĽⷨ��ʹ��hashmap
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int ans = 0;
		int start = 0;
		int end = 0;
		int length = 0;
		unordered_map<char, int> hash;
		while (end < n)
		{
			if (hash.find(s.at(end)) != hash.end() && hash[s.at(end)] >= start)
			{
				start = hash[s.at(end)] + 1;
				length = end - start;
			}
			hash[s.at(end)] = end;

			++end;
			++length;
			ans = max(length, ans);
		}
		return ans;

	}
};


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//�����Ǽ򵥵Ļ�������˼�룬���ж�set���ݽṹ�Ŀ���
		//��ʹ��hashmap������map���ݽṹ���п���
		//�������õĽⷨ��ʹ��hashmap + ˫ָ�룬���׶�Ч�ʸ�
		unordered_map<char, int> col; //{�ַ��� λ��}
		int i = 0;
		int j = 0;
		int length = 0;
		int ans = 0;
		//i�϶�С��j, ��j���ʱ��i�������ظ��ַ��ִ��ĳ��Ȼ��С
		while (j < s.size())
		{
			if (col.find(s[j]) != col.end() && col[s[j]] >= i) //˵��map���и�Ԫ�أ����ʱ��iҪ���£����Ҹ���Ԫ��Ҫ������, col[s[j]] >= i��֤�˳��ֵ��ַ��±���ڴ���������±꣬�������Ҫ
			{
				i = col[s[j]] + 1; //����key������val;
				//���´�ʱ����
				length = j - i;

			}
			col[s[j]] = j; //����Ԫ�أ�����map����û��s[j]���Ԫ�أ�s[j]�����뱻����,����˵�Ǹ���
			j++;
			length++;
			ans = max(ans, length);
		}
		return ans;
	}
};