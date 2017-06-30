//Valid Parenthesis
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isValid(string s) {
	stack<char> stk;
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		if (*iter == '(' || *iter == '{' || *iter == '[')
			stk.push(*iter);
		else if (stk.empty() || *iter - stk.top() <= 0 || *iter - stk.top() >= 3)
			return false;
		else
			stk.pop();
	}
	return stk.empty();
}

int main() {
	cout << isValid("({}([]))")<<endl;
	cout << isValid("((]");
	cout << isValid("{]");
	cout << isValid("(){}[]");
	cout << isValid("") << endl;
	return 0;
}