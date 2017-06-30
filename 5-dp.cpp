//Longest Palindromic Substring
#include<iostream>
#include<string>
using namespace std;

//expand center
string longestPalindrome(string s) {
	int maxlength = 1, subscr = 0;
	for (int centre = 0; centre < s.length(); centre++) {
		int length = 1;
		while (centre - (length - 1)/2 >= 0 && centre + (length - 1)/2 < s.length())
		{
			if (s.at(centre - (length - 1)/2) == s.at(centre + (length - 1)/2))
			{
				if (length > maxlength) {
					subscr = centre - (length - 1) / 2;
					maxlength = length;
				}
				length += 2;
			}
			else break;
		}
		length = 2;
		while (centre - (length - 1)/2 >= 0 && centre + (length)/2 < s.length())
		{
			if (s.at(centre - (length - 1)/2) == s.at(centre + (length)/2))
			{
				if (length > maxlength) {
					subscr = centre - (length - 1) / 2;
					maxlength = length;
				}
				length += 2;
			}
			else break;
		}
	}
	string result(s.begin() + subscr, s.begin() + (subscr + maxlength));
	return result;
}



//dp
// string longestPalindrome(string s) {
// 	bool** status = new bool*[s.length()];
// 	for (int i = 0; i < s.length(); i++)
// 	{
// 		status[i] = new bool[s.length()];
// 		memset(status[i], 0, sizeof(bool)*s.length());
// 	}
// 	for (int i = 0; i < s.length(); i++)
// 		status[i][i] = true;
// 	int subscr = 0, maxlength = 1;
// 	for (int i = 0; i < s.length() - 1; i++)
// 	{
// 		if (s.at(i) == s.at(i + 1)) {
// 			status[i][i + 1] = true;
// 			maxlength = 2;
// 			subscr = i;
// 		}
// 	}
// 	
// 	for (int length = 3; length <= s.length(); length++) {
// 		bool exist = false;
// 		for (int curr = 0; curr < s.length() + 1 - length; curr++)
// 		{
// 			if (status[curr+1][curr + length - 2] == true && s.at(curr) == s.at(curr + length - 1)) {
// 				status[curr][curr + length - 1] = true;
// 				maxlength = length;
// 				subscr = curr;
// 			}
// 		}
// 	}
// 	string result(s.begin() + subscr, s.begin() + (subscr + maxlength));
// 	for (int i = 0; i < s.length(); i++)
// 		delete[] status[i];
// 	delete[] status;
// 	return result;
// }

int main() {
	string str;
	cin >> str;
	cout<<longestPalindrome(str);
	//A->A abba->abba aba->aba
	return 0;
}