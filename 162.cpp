//162. Find Peak Element 6ms 13.48%
// A peak element is an element that is greater than its neighbors.
// 
// Given an input array where num[i] ? num[i + 1], find a peak element and return its index.
// 
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// 
// You may imagine that num[-1] = num[n] = -? .
// 
// For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int findPeakElement(vector<int>& nums) {
	int hi = nums.size()-1;
	int lo = 0;
	while (lo < hi) {
		if (hi - lo == 1)
			if (nums.at(lo) < nums.at(hi))
				return hi;
			else
				return lo;
		int mid = (lo + hi) / 2;
		if (nums.at(mid - 1) > nums.at(mid))
			hi = mid;
		else if (nums.at(mid + 1) > nums.at(mid))
			lo = mid;
		else
			return mid;
	}
	return lo;
}


int main() {
	vector<int> test_case1 = { 1, 2, 3, 1 };
	vector<int> test_case2 = { 3 };
	vector<int> test_case3 = { 1,2 };
	vector<int> test_case4 = { 1,2,3,4,5,6,7,8,9 };
	vector<int> test_case5 = { 1,9,2,0,-1,-5,-8 };

	vector<int> test_case6 = { 1,2,4,9,0,-1,-5,-8 };
	vector<int> test_case7 = { 1,2,3,4,5,6,7,8,9,10,11,5,3,2 };
	cout << findPeakElement(test_case1) << endl;
	cout << findPeakElement(test_case2) << endl;
	cout << findPeakElement(test_case3) << endl;
	cout << findPeakElement(test_case4) << endl; 
	cout << findPeakElement(test_case5) << endl;
	cout << findPeakElement(test_case6) << endl;
	cout << findPeakElement(test_case7) << endl;
	return 0;
}