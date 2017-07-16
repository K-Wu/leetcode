// 154. Find Minimum in Rotated Sorted Array II
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// 
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// Find the minimum element.
// 
// The array may contain duplicates.
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
	int lo = 0;
	int hi = nums.size() - 1;
	int min = (lo + hi) / 2;
	if (nums.at(lo) < nums.at(hi))
		return nums.at(lo);
	else if (nums.at(lo) > nums.at(hi)) {
		while (lo < hi) {
			if (hi - lo == 1) {
				if (nums.at(lo) < nums.at(hi))
					return nums.at(lo);
				else
					return nums.at(hi);
			}
			int mid = (lo + hi) / 2;
			if (nums.at(lo) <= nums.at(mid)) {
				lo = mid;
			}
			else
				hi = mid;

		}
		return nums.at(lo);
	}
	else {
		int min = 0x7fffffff;
		for (int i = 0; i < nums.size(); i += 1) {
			if (nums.at(i) < min)
				min = nums.at(i);
		}
		return min;
	}
}

int main() {
	vector<int> param1 = { 1 };
	int result = findMin(param1);

	return 0;
}