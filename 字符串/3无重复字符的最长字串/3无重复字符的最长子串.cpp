//暴力法
//超出时间限制
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
//使用滑动窗口
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
				j++;  //窗口向右移动
			}
			else
				set.erase(s.at(i++));  //i++
		}
		return ans;
	}
};
*/
//使用hashmap
//这道题最好的解法是使用hashmap
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
		//并不是简单的滑动窗口思想，还有对set数据结构的考察
		//若使用hashmap，还对map数据结构进行考察
		//这道题最好的解法是使用hashmap + 双指针，简单易懂效率高
		unordered_map<char, int> col; //{字符， 位置}
		int i = 0;
		int j = 0;
		int length = 0;
		int ans = 0;
		//i肯定小于j, 当j最大时，i会变大，无重复字符字串的长度会变小
		while (j < s.size())
		{
			if (col.find(s[j]) != col.end() && col[s[j]] >= i) //说明map中有该元素，这个时候i要跟新，并且该新元素要被更新, col[s[j]] >= i保证了出现的字符下标大于窗口最左端下标，这个很重要
			{
				i = col[s[j]] + 1; //根据key，访问val;
				//更新此时长度
				length = j - i;

			}
			col[s[j]] = j; //插入元素，无论map中有没有s[j]这个元素，s[j]都必须被插入,或者说是更新
			j++;
			length++;
			ans = max(ans, length);
		}
		return ans;
	}
};