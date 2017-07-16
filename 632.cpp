//632. Smallest Range 889ms Using pointers
// You have k lists of sorted integers in ascending order.Find the smallest range that includes at least one number from each of the k lists.
	// 
	// We define the range[a, b] is smaller than range[c, d] if b - a < d - c or a < c if b - a == d - c.
	// 
	// 	Example 1:
	// Input:[[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]]
	// 	Output : [20, 24]
	// 	Explanation :
	// 	List 1 : [4, 10, 15, 24, 26], 24 is in range[20, 24].
	// 	List 2 : [0, 9, 12, 20], 20 is in range[20, 24].
	// 	List 3 : [5, 18, 22, 30], 22 is in range[20, 24].
	// 	Note :
	// 	The given list may contain duplicates, so ascending order means >= here.
	// 	1 <= k <= 3500
	// 	- 105 <= value of elements <= 105.
	// 	For Java users, please note that the input type has been changed to List<List<Integer>>.And after you reset the code template, you'll see this point.

#include<vector>

using namespace std;
void findMaxMin_experimental(vector<vector<int>>& nums, vector<int>& ptr, int& min, int& min_ind, int& max) {
	//返回第一个数是最大值，第二个数是第几个list，第三个数是最小值，第四个数是第几个list
	max = nums[0][ptr[0]];
	//max_ind = 0;
	min = nums[0][ptr[0]];
	min_ind = 0;
	for (int i = 0; i < nums.size(); i += 1) {
		int curr = nums[i][ptr[i]];
		if (max < curr) {
			max = curr;
			//max_ind = i;
		}
		if (min > curr) {
			min = curr;
			min_ind = i;
		}
	}
	//vector<int> result = { max,max_ind,min,min_ind };
	return;
}

vector<int> smallestRange(vector<vector<int>>& nums) {
	int k = nums.size();
	vector<int> ptr(k, 0);
	vector<int> curr;
	for (int i = 0; i < k; i += 1) {
		//if(nums[i].empty()) impossible
		curr.push_back(nums[i][0]);
	}
	bool flag = true;
	vector<int> range = { -1111111,111111 };
	while (flag) {
		int min, min_ind, max;
		findMaxMin_experimental(nums, ptr, min, min_ind, max);
		if (range[1] - range[0] > max - min) {//写成了小于号
			range[0] = min;
			range[1] = max;
		}
		if (nums[min_ind].size() == ptr[min_ind] + 1)//写成了-1
			return range;
		else
			ptr[min_ind] += 1;
	}


}

// vector<int> findMaxMin(vector<vector<int>>& nums, vector<int>& ptr) { //正确的方法 但速度太慢 1009ms，5.97%
// 	//返回第一个数是最大值，第二个数是第几个list，第三个数是最小值，第四个数是第几个list
// 	int max = nums[0][ptr[0]];
// 	int max_ind = 0;
// 	int min = nums[0][ptr[0]];
// 	int min_ind = 0;
// 	for (int i = 0; i < nums.size(); i += 1) {
// 		int curr = nums[i][ptr[i]];
// 		if (max < curr) {
// 			max = curr;
// 			max_ind = i;
// 		}
// 		if (min > curr) {
// 			min = curr;
// 			min_ind = i;
// 		}
// 	}
// 	vector<int> result = {max,max_ind,min,min_ind};
// 	return result;
// 
// }

// vector<int> smallestRange(vector<vector<int>>& nums) { //正确的方法 但速度太慢 1009ms，5.97%
// 	int k = nums.size();
// 	vector<int> ptr(k, 0);
// 	vector<int> curr;
// 	for (int i = 0; i < k; i += 1) {
// 		//if(nums[i].empty()) impossible
// 		curr.push_back(nums[i][0]);
// 	}
// 	bool flag = true;
// 	vector<int> range = { -1111111,111111 };
// 	while (flag) {
// 		vector<int> result = findMaxMin(nums, ptr);
// 		if (range[1] - range[0] > result[0] - result[2]) {//写成了小于号
// 			range[0] = result[2];
// 			range[1] = result[0];
// 		}
// 		int min_ind = result[3];
// 		if (nums[min_ind].size() == ptr[min_ind] + 1)//写成了-1
// 			return range;
// 		else
// 			ptr[min_ind] += 1;
// 	}
// 
// 
// }




int main() {
	vector<vector<int>> param1 = { {4, 10, 15, 24, 26},{0, 9, 12, 20},{5, 18, 22, 30} };
	vector<int> result = smallestRange(param1);
	vector<vector<int>> param2 = { { 3,6 },{ 5 } };
	vector<int> result2 = smallestRange(param2);
	return 0;
}