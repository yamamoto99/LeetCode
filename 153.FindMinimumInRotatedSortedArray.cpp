#include <vector>
#include <algorithm>

class Solution {
public:
	int findMin(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[0];
	}
};