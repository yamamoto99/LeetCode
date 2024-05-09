#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		for(int i = 0; i < nums.size(); i++)
		{
			int serchValue = target - nums[i];
			if (map.count(serchValue))
				return {map.at(serchValue), i};
			map[nums[i]] = i;
		}
		return {0, 0};
	}
};