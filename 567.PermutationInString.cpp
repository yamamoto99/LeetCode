#include <string>
#include <unordered_map>

class Solution {
public:
	bool checkInclusion(std::string s1, std::string s2) {
		int s1_len = s1.size();
		int s2_len = s2.size();
		std::unordered_map<char, int> s1_map;
		std::unordered_map<char, int> s2_map;

		if (s1_len > s2_len)
			return false;
		for (int i = 0; i < s1_len; i++)
		{
			s1_map[s1[i]]++;
			s2_map[s2[i]]++;
		}
		if (s1_map == s2_map)
			return true;
		for (int i = s1_len; i < s2_len; i++)
		{
			s2_map[s2[i]]++;
			s2_map[s2[i - s1_len]]--;
			if (s2_map[s2[i - s1_len]] == 0)
				s2_map.erase(s2[i - s1_len]);
			if (s1_map == s2_map)
				return true;
		}
		return false;
	}
};