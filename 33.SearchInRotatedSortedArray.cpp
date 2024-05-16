#include <vector>
#include <unordered_map>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
			map.insert({nums[i], i});
		if (map.count(target))
			return map.at(target);
		return -1;
	}
};