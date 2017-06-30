#include<iostream>
#include<string>
using namespace std;
string convert(string s, int numRows)
{
	if (s.length() < numRows||numRows==1) return s;
	char* strtmp = new char[s.length() + 1];
	int i = 0;
	int curr = 0;
	while (i <= s.length() - 1)
	{
		strtmp[curr++] = s.at(i);
		i += (2*numRows - 2);
	}
	for (int j = 1; j < numRows-1; j++) {
		int k = j;
		while (k <= s.length() - 1) {
			strtmp[curr++] = s.at(k);
			k += (numRows - 1);
		}
	}
	i = numRows-1;
	while (i <= s.length() - 1)
	{
		strtmp[curr++] = s.at(i);
		i += (2*numRows -2);
	}
	strtmp[s.length()] = 0;
	string result(strtmp);
	delete[] strtmp;
	return result;
}
int main() {
	string str;
	int numRows;
	cin >> str>>numRows;
	cout << convert(str, numRows);
	return 0;
}