// 451. Sort Characters By Frequency
// Given a string, sort it in decreasing order based on the frequency of characters.
#include<string>
#include<vector>
using namespace std;

string frequencySort(string s) {
	int freq[256];
	
	int len = s.size();
	if (len == 0) return "";
	vector<string> freq_string(len+1, "");//1大小应该为len而不是256 //4.len==0会出错//8大小应该为len+1
	string result;
	for (int i = 0; i <= 255; i += 1) {
		freq[i] = 0;
	}
	for (int i = 0; i < len; i += 1)
	{
		freq[s[i]] += 1;
	}
	for (int i = 255; i >= 0; i -= 1) {//3忘记修改此处的初始值为len//5应为len-1//6应为256//7应为255
		if (freq[i] > 0) {
			freq_string[freq[i]].append(freq[i], i);
		}
	}
	for (int i = len; i >= 0; i -= 1) {//2忘记修改此处的初始值为len//5应为len-1//9freq_dict长度修改成len+1以后这里应该修改成len
		if (freq_string[i].size() > 0) {
			result.append(freq_string[i]);
		}
	}
	return result;
}

int main() {
	string e = frequencySort("eeeeee");
	string a = frequencySort("tree");
	string b = frequencySort("cccaaa");
	string c = frequencySort("Aabb");
	frequencySort("");
	return 0;

}