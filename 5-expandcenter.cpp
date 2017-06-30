//Longest Palindromic Substring
#include<iostream>
#include<string>
using namespace std;

//expand center
string longestPalindrome(string s) {
	int maxlength = 1, subscr = 0;
	for (int centre = 0; centre < s.length(); centre++) {
		int length = 1;
		while (centre - (length - 1) / 2 >= 0 && centre + (length - 1) / 2 < s.length())
		{
			if (s.at(centre - (length - 1) / 2) == s.at(centre + (length - 1) / 2))
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
		while (centre - (length - 1) / 2 >= 0 && centre + (length) / 2 < s.length())
		{
			if (s.at(centre - (length - 1) / 2) == s.at(centre + (length) / 2))
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