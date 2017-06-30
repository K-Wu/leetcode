// word - break - ii
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
// 
// Return all such possible sentences.
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

vector<string> search_string(string s, unordered_set<string> & wordDict) {
	int len = s.length();
	vector<string> result;
	for (int i = 1; i < len; i++) {
		if (wordDict.find(s.substr(0, i)) != wordDict.end())
		{
			string new_prefix_with_space=s.substr(0, i)+" ";

			vector<string> sub_result = search_string(s.substr(i, len - i), wordDict);//i,len-i计算卡了一下，进行了测试，发现是对的；对i==len进行了测试
			for (string str : sub_result) {
				result.push_back(new_prefix_with_space + str);
			}
		}
	}
	if (wordDict.find(s) != wordDict.end())//终止条件未写，
		result.push_back(s);

	return result;
}
vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
	// Write your code here

	vector<string> result = search_string(s, wordDict);
	return result;
}
int main() {

	string s("abcddefg");
	string a = s.substr(8, 0);
	string b = s.substr(0, 1);
	string c = s.substr(1, 7);
	string str_to_search("lintcode");
	unordered_set<string> wordDict = { string("de"), string("ding"), string("co"), string("code"), string("lint") };
	vector<string> res = wordBreak(str_to_search, wordDict);
	return 0;
}