#include <algorithm>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		int min_value = INT_MAX;
		int profit = 0;
		for (int price : prices)
		{
			min_value = std::min(min_value, price);
			profit = std::max(profit, price - min_value);
		}
		return profit;
	}
};