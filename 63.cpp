
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid.at(0).size();
	bool m_flag = false;
	bool n_flag = false;
	int * arr = new int[m*n];
	for (int i = 0; i < m*n; i++)
		arr[i] = 0;
	for (int i = 0; i < m; i++)
	{
		if (obstacleGrid.at(i).at(0) == 1)
			m_flag = true;
		if(m_flag==false)//本来为~m_flag，发现为false时~m_flag为int -2；非是!
			arr[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{

		if (obstacleGrid.at(0).at(i) == 1)
			n_flag = true;//拷贝成m_flag
		if(n_flag==false)
			arr[i*m] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (obstacleGrid.at(j).at(i) == 1) {
				arr[i*m + j] = 0;
			}
			else
			arr[i*m + j] = arr[(i - 1)*m + j] + arr[i*m + j - 1];
		}
	}
	int result = arr[m*n - 1];
	delete[] arr;
	return result;
}


int main() {
	//int a = uniquePaths(10, 2);//10
	//int b = uniquePaths(10, 1);//1
	vector<vector<int>> param = {
		{0, 0, 0},
		{0, 1, 0 },
		{0, 0, 0 }
	};
	vector<vector<int>> param2 = { {1} };
	//int result = uniquePathsWithObstacles(param);

	int result2 = uniquePathsWithObstacles(param2);

	return 0;
}