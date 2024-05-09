#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> res;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			int target = -nums[i];
			int front = i + 1;
			int end = len - 1;
			while (front < end)
			{
				int sum = nums[front] + nums[end];
				if (sum < target)
					front++;
				else if (sum > target)
					end--;
				else
				{
				std::vector<int> triplet = {nums[i], nums[front], nums[end]};
				res.push_back(triplet);
				// 今見てた数値から違う数値になるまでインクリメント
				while (front < end && nums[front] == triplet[1])
					front++;
				// 今見てた数値から違う数値になるまでデクリメント
				while (front < end && nums[end] == triplet[2])
					end--;
				}
			}
			// 次の数値が今見てた数値と同じ場合インクリメント
			while (i + 1 < len && nums[i + 1] == nums[i]) 
				i++;
		}
		return res;
	}
};