#include <unordered_set>
#include <vector>

class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> set;
		for (int num : nums)
		{
			if (set.count(num) > 0)
				return true;
			set.insert(num);
		}
		return false;
	}
};