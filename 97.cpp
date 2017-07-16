// 97. Interleaving String 3ms 16.38%
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
// 
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
// 
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
#include<iostream>
#include<string>
using namespace std;
int get_ind(int i1, int i2, int sz1, int sz2) {
	return ((sz2+1)*i1 + i2);
}

bool isInterleave(string s1, string s2, string s3) {
	int length1 = s1.size();
	int length2 = s2.size();
	//-%s3的长度可能与s1、s2不同
	if (length1 + length2 != s3.size())
		return false;
	bool* available = new bool[(length1+1)*(length2+1)];
	available[0] = true;
	for (int i = 1; i <= length1; i++) {
		if (available[get_ind(i - 1, 0, length1, length2)] && s3.at(i-1) == s1.at(i-1))
			available[get_ind(i, 0, length1, length2)] = true;
		else
			available[get_ind(i, 0, length1, length2)] = false;
	}
	for (int i = 1; i <= length2; i++) {
		if (available[get_ind(0, i-1, length1, length2)] && s3.at(i-1) == s2.at(i-1))
			available[get_ind(0, i, length1, length2)] = true;
		else
			available[get_ind(0, i, length1, length2)] = false;
	}
	for (int i1 = 1; i1 <= length1; i1++) {
		for (int i2 = 1; i2 <= length2; i2++) {
			if (available[get_ind(i1, i2 - 1, length1, length2)] && s3.at(i1+i2-1) == s2.at(i2-1))
				available[get_ind(i1, i2, length1, length2)] = true;
			else if (available[get_ind(i1 - 1, i2, length1, length2)] && s3.at(i1+i2-1) == s1.at(i1-1))
				available[get_ind(i1, i2, length1, length2)] = true;
			else 
				available[get_ind(i1, i2, length1, length2)] = false;
		}
	}
	bool result = available[get_ind(length1, length2, length1, length2)];
	delete[] available;
	return result;
}


int main() {
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3t = "aadbbcbcac";
	string s3f = "aadbbbaccc";
	string case1_s1 = "";
	string case1_s2 = "abc";
	string case1_s22 = "";
	cout << isInterleave(s1, s2, s3t) << endl;
	cout << isInterleave(s1, s2, s3f) << endl;
	cout << isInterleave(case1_s1, case1_s2, case1_s2)<<endl;
	cout << isInterleave(case1_s1, case1_s22, case1_s22) << endl;
	return 0;

}