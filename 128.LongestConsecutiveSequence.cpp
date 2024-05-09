#include <stack>
#include <vector>
#include <algorithm>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums) {
		if (nums.empty())
			return 0;
		std::stack<int> s;
		int res = 0;
		std::sort(nums.begin(), nums.end());
		s.push(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			if (s.top() == nums[i])
				continue;
			if (s.top() == nums[i] - 1)
				s.push(nums[i]);
			else
			{
				if (res < s.size())
					res = s.size();
				while (!s.empty())
					s.pop();
				s.push(nums[i]);
			}
		}
		return res < s.size() ? s.size() : res;
	}
};