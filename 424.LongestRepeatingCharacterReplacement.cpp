#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	int characterReplacement(std::string s, int k) {
		std::unordered_map<char, int> count;
		int maxCount = 0;
		int start = 0;
		for (int end = 0; end < s.size(); end++) 
		{
			// 現在のWindow内で最も頻繁に出現する文字の最大数を検索
			// この時、maxCountが現在のWindow内で最も頻繁に出現する文字の最大数を超えることは問題がなく、
			// window内の最大数がmaxCount以上にならない限りWindowを移動し続けることになる
			maxCount = std::max(maxCount, ++count[s[end]]);
			// 最も頻繁に出現する文字以外の文字数がkを超える場合、windowをずらす
			if (end - start + 1 - maxCount > k)
				count[s[start++]]--;
		}
		return s.size() - start;
	}
};