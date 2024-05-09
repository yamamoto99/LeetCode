#include <vector>
#include <algorithm>

class Solution {
public:
	int trap(std::vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max_left = 0;
		int max_right = 0;
		int res = 0;
		while (left < right) {
			// 左のハーの方が低い時
			if (height[left] < height[right]) {
				// max_leftより高い場合更新、低い場合はmax_leftと現在地の高さの差=水のたまる量なのでresにプラス
				height[left] >= max_left ? (max_left = height[left]) : res += (max_left - height[left]);
				++left;
			}
			else {
				// max_rightより高い場合更新、低い場合はmax_rightと現在地の高さの差=水のたまる量なのでresにプラス
				height[right] >= max_right ? (max_right = height[right]) : res += (max_right - height[right]);
				--right;
			}
		}
		return res;
	}
};