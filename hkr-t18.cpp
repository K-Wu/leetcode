#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
// bool testPalindrome(string str)
// {
// 	queue<char> que;
// 	stack<char> stk;
// 	for (char ch: str)
// 	{
// 		que.push(ch);
// 		stk.push(ch);
// 	}
// 	while (!que.empty()) {
// 		if (que.front() != stk.top())
// 			return false;
// 		que.pop();
// 		stk.pop();
// 	}
// 	return true;
// 
// 
// }
class Solution {
	//Write your code here
private:
	char* queue;
	char* stack;
	int quepos;
	int stkpos;
	int quebeg;
public:
	Solution() {
		queue = new char[200];
		stack = new char[200];
		quepos = 0;
		quebeg = -1;
		stkpos = 0;
	}
	void pushCharacter(char ch) {
		stack[stkpos++] = ch;
	}
	void enqueueCharacter(char ch) {
		queue[quepos++] = ch;
	}
	char popCharacter() {
		return stack[--stkpos];
	}
	char dequeueCharacter() {
		return queue[++quebeg]; 
	}
};
int main() {
	// read the string s.
	string s;
	getline(cin, s);

	// create the Solution class object p.
	Solution obj;

	// push/enqueue all the characters of string s to stack.
	for (int i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s << ", is not a palindrome.";
	}

	return 0;
}