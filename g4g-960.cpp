//Valid Substring
#include<stdio.h>
#include<stack>
#include<cstring>
#include<assert.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	char str[120];
	//-1 for (, -2 for )
	for (int i = 0; i < T; i++)
	{
		scanf("%s", str);
		stack<int> stk;
		int pos = 0;
		int rightMinusLeft = 0;
		for (; pos < strlen(str); pos++) {
			if (str[pos] == '(')
			{
				stk.push(-1);
				rightMinusLeft--;
			}
			else if (str[pos] == ')') {
				if (rightMinusLeft == 0)
				{
					stk.push(-2);
					continue;
				}
				rightMinusLeft++;
				int curr = 0;
				assert(stk.top() != -2);
				while (stk.top() != -1 && stk.top() != -2) {
					curr += stk.top();
					stk.pop();
				}
				assert(stk.top() != -2);
				curr += 2;
				stk.pop();
				stk.push(curr);
			}
		}
		int max = 0;
		int curr = 0;
		while (!stk.empty()) {
			if (stk.top() != -1 && stk.top() != -2) {
				curr += stk.top();
			}
			else {
				if (max < curr)
					max = curr;
				curr = 0;
			}
			stk.pop();
		}

		if (max < curr)
			max = curr;
		printf("%d\n", max);

	}
	return 0;
	
}