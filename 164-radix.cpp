// 164. Maximum Gap 9ms 31.48%
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// 
// Try to solve it in linear time / space.
// 
// Return 0 if the array contains less than 2 elements.
// 
// You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
#include<vector>
#include<algorithm>
// radix sort
using namespace std;
int max2(int a, int b) {
	return a > b ? a : b;
}
int maximumGap(vector<int>& nums) {
	if (nums.empty()||nums.size() < 2)
		return 0;
	int maxVal = *max_element(nums.begin(),nums.end());
	int exp = 1;
	int radix = 10;
	while (maxVal / exp > 0) {
		vector<int> count(radix, 0);
		vector<int> aux(nums.size());
		for (int i = 0; i < nums.size(); i += 1)
			count[nums[i]/exp %10] += 1;
		for (int i = 1; i < count.size(); i += 1)
			count[i] += count[i - 1];
		for (int i = nums.size()-1; i >= 0; i -= 1) {//%应该从后往前遍历
			int rad_ = nums[i] / exp % 10;
			aux[--count[rad_]] = nums[i];
		}
		nums = aux;
		exp *= 10;
	}
	int result = -1;
	for (int i = 1; i < nums.size(); i += 1) {
		result = max2(result, nums[i] - nums[i - 1]);
	}
	return result;//-%修改maxVal为result后这里忘记修改
}

int main() {
	vector<int> param0 = {};
	vector<int> param1 = { 1,1,1,1,1,5,5,5,5,5 };//%runtime-error division by zero
	vector<int> param2 = { 1 };
	vector<int> param3 = { 1,1 };
	vector<int> param4 = { 1,4,5,7,9 };
	vector<int> param5 = { 1,3,5,7,11,13,19,21 };
	int res0 = maximumGap(param0);
	int res1 = maximumGap(param1);
	int res2 = maximumGap(param2);
	int res3 = maximumGap(param3);
	int res4 = maximumGap(param4);
	int res5 = maximumGap(param5);

	return 0;
}