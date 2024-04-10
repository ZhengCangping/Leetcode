#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> hashset;	//��ǰ�������ڵ��ַ���
		int right = 0;//��ָ��
		int maxLength = 0;
		int nowLength = 0;
		//��ָ��ÿ��+1{��ָ���ҵ����}
		for (int left = 0; left < s.size(); left++) {//��ָ��
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
