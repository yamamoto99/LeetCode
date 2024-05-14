#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			if (nums[left] == target)
				return left;
			if (nums[right] == target)
				return right;
			left++;
			right--;
		}
		return -1;
	}
};