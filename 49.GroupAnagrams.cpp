#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::unordered_map<std::string, std::vector<std::string>>map;
		for (std::string str : strs)
		{
			std::string serchString = str;
			std::sort(serchString.begin(), serchString.end());
			map[serchString].push_back(str);
		}
		std::vector<std::vector<std::string>>res;
		for (auto i : map)
			res.push_back(i.second);
		return res;
	}
};