#include <vector>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int left = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int right = m * n - 1;
		while (left <= right)
		{
			int mid = (right - left) / 2 + left;
			int midVal = matrix[mid / n][mid % n];
			if (midVal == target)
				return true;
			else if (midVal < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}
};