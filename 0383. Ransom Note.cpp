//使用两个哈希表
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> ran;
		unordered_map<char, int> mag;
		for (int i = 0; i < ransomNote.size(); ++i)
			ran[ransomNote[i]]++;
		for (int i = 0; i < magazine.size(); ++i)
			mag[magazine[i]]++;
		for (auto i : ran)
		{

			if (mag[i.first] >= i.second)
				;
			else
				return false;
		}
		return true;
	}
};