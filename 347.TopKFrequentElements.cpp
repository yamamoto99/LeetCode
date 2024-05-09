#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int>map;
		std::priority_queue<std::pair<int, int>>pq;
		for (int i = 0; i < nums.size(); i++)
			map[nums[i]]++;
		for (auto i : map)
			pq.push({i.second, i.first});
		std::vector<int> res;
		while(k--)
		{
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};