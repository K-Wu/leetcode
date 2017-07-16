// 75. Sort Colors 6ms 1.73%
// One pass
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// 
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// 
// Note:
// You are not suppose to use the library's sort function for this problem.
// 
// click to show follow up.
// 
// Follow up :
// A rather straight forward solution is a two - pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// 
// Could you come up with an one - pass algorithm using only constant space ?
#include<vector>


using namespace std;

void sortColors(vector<int>& nums) {
	if (nums.empty() || nums.size() == 1)
		return;
	int zero_ptr = 0;
	int two_ptr = nums.size() - 1;
	int curr_ptr = 0;
	while (curr_ptr <= two_ptr) {
		if (nums[curr_ptr] == 0) {
			nums[curr_ptr] = nums[zero_ptr];
			if (zero_ptr == curr_ptr)//%out of range
				curr_ptr++;
			nums[zero_ptr++] = 0;
			continue;//% out of range
		}
		if (nums[curr_ptr] == 2) {
			nums[curr_ptr] = nums[two_ptr];
			if (two_ptr == curr_ptr)
				curr_ptr++;
			nums[two_ptr--] = 2;
			continue;
		}
		if (nums[curr_ptr] == 1) {
			curr_ptr++;
		}
	}
}
int main() {
	vector<int> test_case1 = { 0,2,1 };
	vector<int> test_case2 = { 0,0,0,0 };
	vector<int> test_case3 = { 2,2,2,2 };
	vector<int> test_case4 = { 1,0,0,2,2,0,1 };
	vector<int> test_case5 = { 0,0,0,0,0,1,1,1,1,1,2,2,2,2 };
	vector<int> test_case6 = { 1,1,1,1,1,1,1,1,1,2,2,2,2 };
	sortColors(test_case1);
	sortColors(test_case2);
	sortColors(test_case3);
	sortColors(test_case4);
	sortColors(test_case5);
	sortColors(test_case6);

	return 0;
}