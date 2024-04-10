#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> hashset;	//当前滑动窗口的字符集
		int right = 0;//右指针
		int maxLength = 0;
		int nowLength = 0;
		//左指针每轮+1{右指针找到最大}
		for (int left = 0; left < s.size(); left++) {//左指针
			while (right < s.size() && !hashset.count(s[right])) {
				hashset.insert(s[right]);
				right++;
			}
			nowLength = right - left;
			if (nowLength > maxLength) maxLength = nowLength;

			hashset.erase(s[left]);
		}

		return maxLength;
	}
};

int main() {
	string s = "abcaabcbb";

	Solution sol;
	int res = sol.lengthOfLongestSubstring(s);

	return 0;
}
