#include<vector>
#include<string>
using namespace std;
bool validPeriod(string s) {
	if (s.length() == 0)//corner case 1
		return false;
	if (s[0] == '0' /*corner case 2*/&&s.length()!=1/*corner case3*/)
		return false;
	int a = atoi(s.c_str());
	if (a <= 255 && a >= 0)
		return true;
	else
		return false;
}
int min(int a, int b) {
	return a > b ? b : a;
}
vector<string> restoreIpAddresses(string s, int n) {
	int len = s.length();
	vector<string> result;
	if (n == 1)//忘记边界条件
	{
		if (validPeriod(s)) {

			result.push_back(s);
			return result;
		}
		else
			return result;
	}
	for (int i = 1; i <= min(len, 3); i++)
	{
		if (validPeriod(s.substr(0, i))) {
			vector<string> vec_str = restoreIpAddresses(s.substr(i, len), n - 1);
			for (auto item = vec_str.begin(); item != vec_str.end(); item++)
				result.push_back(s.substr(0, i) + "." + *item);
		}
	}
	return result;
}
vector<string> restoreIpAddresses(string s) {
	return restoreIpAddresses(s, 4);

}



int main() {


	vector<string> result = restoreIpAddresses("25525511135");
	return 0;
}