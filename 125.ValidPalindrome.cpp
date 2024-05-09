#include <string>
#include <iostream>

class Solution {
public:
	bool isPalindrome(std::string s) {
		std::string str;
		for (char c : s)
		{
			if (isalpha(c) || isdigit(c))
				str.push_back(tolower(c));
		}
		int start = 0;
		int end = str.size() - 1;
		while (start <= end)
		{
			if (str[start] != str[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};