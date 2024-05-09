#include <vector>

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int numsMul = 1;
		int zeroCount = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (nums[i] == 0)
			{
				zeroCount++;
				continue;
			}
			numsMul *= nums[i];
		}
		std::vector<int> res(len, 0);
		if (zeroCount == 1)
		{
			for (int i = 0; i < len; i++)
				res[i] = nums[i] == 0 ? numsMul : 0;
		}
		else if (zeroCount == 0)
		{
			for (int i = 0; i < len; i++)
				res[i] = numsMul / nums[i];
		}
		return res;
	}
};
