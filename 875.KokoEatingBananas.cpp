#include <vector>

class Solution {
public:
	int minEatingSpeed(std::vector<int>& piles, int h) {
		int low = 1;
		int high = *max_element(piles.begin(), piles.end());
		while (low < high)
		{
			int mid = (high + low) / 2 + low;
			int total = 0;
			for (int pile : piles)
				total += (pile + mid - 1) / mid;
			if (total > h)
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}
};