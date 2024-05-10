#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int len = s.size() ;
		std::unordered_map<char,int>mp;
		int i = 0;
		int j = 0;
		int res = 0;
		while(j < len){
			mp[s[j]]++;
			while(mp[s[j]] > 1)
				mp[s[i++]]--;
			res = std::max(res, j - i + 1);
			j++;
		}
		return res;
	}
};