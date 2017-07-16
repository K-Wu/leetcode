// 164. Maximum Gap 想法+1处correct+1处case 6ms 73.87%
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// 
// Try to solve it in linear time / space.
// 
// Return 0 if the array contains less than 2 elements.
// 
// You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
#include<vector>

using namespace std;
//使用鸽笼原则
struct Interval {
	int min;
	int max;
	int size;
	Interval() :size(0),min(0x7fffffff),max(-1) {

	}
};
int max2(int a, int b) {
	return a > b ? a : b;
}
int min2(int a, int b) {
	return a < b ? a : b;
}
int maximumGap(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	int max = -1;
	int min = 0x7fffffff;
	for (int i = 0; i < nums.size(); i += 1) {
		if (nums.at(i) > max)
			max = nums.at(i);
		if (nums.at(i) < min)
			min = nums.at(i);
	}
	//if (max == min)//%这一步并不能防止range为0，正确的防止方法是max-min>=nums.size()-1
	//	return 0;
	int range = max2(1,(max - min) / (nums.size()-1));
	int bucketnum = (max - min) / range+1;//%不应该是(max - min + 1) / range
	Interval* intervals = new Interval[bucketnum];
	for (int i = 0; i < nums.size(); i += 1) {
		int ind = (nums.at(i) - min) / range;	
		intervals[ind].max=max2(nums.at(i),intervals[ind].max);
		intervals[ind].min = min2(nums.at(i),intervals[ind].min);
		intervals[ind].size += 1;
	}
	int maxinterval = 0;
	int prevmax = 0x7fffffff;
	for (int i = 0; i < bucketnum; i += 1) {
		if (intervals[i].size == 0)
			continue;
		maxinterval = max2(intervals[i].min - prevmax,maxinterval);
		prevmax = intervals[i].max;
	}
	return maxinterval;
}
int main() {
	vector<int> param1 = {1,1,1,1,1,5,5,5,5,5};//%runtime-error division by zero
	vector<int> param2 = { 1 };
	vector<int> param3 = { 1,1 };
	vector<int> param4 = { 1,4,5,7,9 };
	vector<int> param5 = { 1,3,5,7,11,13,19,21 };
	int res1 = maximumGap(param1);
	int res2 = maximumGap(param2);
	int res3 = maximumGap(param3);
	int res4 = maximumGap(param4);
	int res5 = maximumGap(param5);


	return 0;
}