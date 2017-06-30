

using namespace std;
int uniquePaths(int m, int n) {
	int * arr = new int[m*n];
	for (int i = 0; i < m*n; i++)
		arr[i] = 0;
	for (int i = 0; i < m; i++)
		arr[i] = 1;
	for (int i = 0; i < n; i++)
		arr[i*m] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			arr[i*m + j] = arr[(i - 1)*m + j] + arr[i*m + j - 1];
		}
	}
	int result = arr[m*n - 1];
	delete[] arr;
	return result;
}


int main() {
	int a = uniquePaths(10, 2);//10
	int b = uniquePaths(10, 1);//1




	return 0;
}