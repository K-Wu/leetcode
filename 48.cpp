// You are given an n x n 2D matrix representing an image.
// 
// Rotate the image by 90 degrees(clockwise).
// 
// Follow up :
// Could you do this in - place ?
#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size();
	for (int i = 0; i < len/2; i++) {
		for (int j = i; j < (len-1-i); j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[len - 1 - j][i];
			matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
			matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
			matrix[j][len - 1 - i] = temp;
		}
	}
}
int main() {



	return 0;
}