#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

int clear = 0xFFFFF;
int getBit(char ch) {
	if (ch == 'A')
		return 0;
	else if (ch == 'C')
		return 1;
	else if (ch == 'T')
		return 2;
	else if (ch == 'G')
		return 3;
	return -1;
}
vector<string> findRepeatedDnaSequences(string s) {
	unordered_map<int, int> found;
	int currHash = 0;
	if (s.length() < 10) return{};
	vector<string> vect;
	for (int i = 0; i < 10; i++) {
		currHash = currHash << 2;
		currHash += getBit(s.at(i));
	}
	found.emplace(currHash, 0);
	for (int i = 10; i < s.length(); i++) {
		currHash = currHash << 2;
		currHash = currHash&clear;
		currHash += getBit(s.at(i));
		unordered_map<int, int>::iterator iter;
		if ((iter = found.find(currHash)) != found.end())
		{
			if (iter->second == 0) {
				vect.emplace_back(s.begin() + (i - 9), s.begin() + (i + 1));
				iter->second += 1;
			}
		}
		else {
			found.emplace(currHash, 0);
		}
	}
	return vect;
}

int main() {
	string str1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	findRepeatedDnaSequences(str1);
}