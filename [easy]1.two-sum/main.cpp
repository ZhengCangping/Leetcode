#include<iostream>
#include<assert.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashmap; //(nums[i],i)
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashmap.find(target - nums[i]);
			if (it != hashmap.end()) return { it->second,i };
			hashmap[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	vector<int> nums = { 2,7,11,15 };
	int target = 9;

	Solution s;
	vector<int> res = s.twoSum(nums, target);
}

//哈希表（值，下标）
//哈希表找键用find，返回迭代器