//91. Decode Ways 3ms 13%
// A message containing letters from A - Z is being encoded to numbers using the following mapping :
// 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// 
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// 
// The number of ways decoding "12" is 2.
#include<string>
#include<iostream>
using namespace std;
int str2num(string s) {
	if (s.size() == 1) {
		return (s.at(0) - 48);
	}
	else if (s.size() == 2) {
		int tenth = s.at(0) - 48;
		//-%十位为0无效
		if (tenth!=0)
			return (tenth * 10 + (s.at(1) - 48));
	}
	return -1;
}
bool isAlphaEncode(int encoding) {
	return (1 <= encoding) && (encoding <= 26);//写成了<<
}
int numDecodings(string s) {
	int length = s.size();
	int* sum = new int[length+1];//方法总数
	if (length == 0)
		return 0;
	sum[0] = 1;
	if (isAlphaEncode(str2num(s.substr(0, 1))))
		sum[1] = 1;
	else
		sum[1] = 0;//%%没有考虑0
	for (int i = 2; i < length+1; i += 1) {
		sum[i] = 0;
		if (isAlphaEncode(str2num(s.substr(i - 1, 1))))
			sum[i] += sum[i - 1];
		if (isAlphaEncode(str2num(s.substr(i - 2, 2)))) {//%将i的定义+1后这里忘记-1
			sum[i] += sum[i - 2];
		}
	}
	int result = sum[length];
	delete[] sum;
	return result;
}
int main() {
	cout << numDecodings("014") << endl;
	cout << numDecodings("12") << endl;
	cout << numDecodings("") << endl;
	cout << numDecodings("1") << endl;
	cout << numDecodings("123") << endl;
	cout << numDecodings("321") << endl;

	return 0;
}