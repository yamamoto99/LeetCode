#include <vector>
#include <unordered_set>

class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> set;
		int numsLen = nums.size();
		for (int i = 0; i < numsLen; i++)
		{
			if (set.count(nums[i]))
				return nums[i];
			set.insert(nums[i]);
		}
		return ;
	}
};