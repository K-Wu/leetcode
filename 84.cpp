//84. Largest Rectangle in Histogram
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}

int getMaxArea_ref(int hist[], int n)
{
	// from GeeksforGeeks
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	stack<int> s;

	int max_area = 0; // Initalize max area
	int tp; // To store top of stack
	int area_with_top; // To store area with top bar as the smallest bar

					   // Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, then calculate area of rectangle 
		// with stack top as the smallest (or minimum height) bar. 'i' is 
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.top(); // store the top index
			s.pop(); // pop the top

					 // Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}


int largestRectangleArea(vector<int>& heights) {
	//%%无法解决{2,1,2}
	stack<int> stk;
	int result = 0;
	for (int i = 0; i < heights.size(); i += 1) {
		int less_left = -1;
		while (!stk.empty()) {
			int stktop = stk.top();
			if (heights.at(stktop) < heights.at(i)) {//%这里没有将less_left修改成修改后的stktop
				less_left = stktop;
				break;
			}
			stk.pop();
		}
		result = max(result, heights.at(i)*(i-less_left));
		
		stk.push(i);
	}

	stack<int> stk_right;
	for (int i = heights.size()-1; i > -1; i -= 1) {
		int less_right = heights.size();
		while (!stk_right.empty()) {
			int stktop = stk_right.top();//%%用了stk，应该用stk_right
								   //%%直接修改了less_right，因此在右/左侧没有更小的数时，没有将less_right/left还原成size()/-1

			if (heights.at(stktop) < heights.at(i)) {
				{
					less_right = stktop;
					break; 
				}
			}
			
			stk_right.pop();
		}
		result = max(result, heights.at(i)*(less_right-i));

		stk_right.push(i);
	}
	return result;
}

int main() {
	vector<int> test_case1 = { 1,1 };
	cout<<largestRectangleArea(test_case1)<<endl;
	int test_case2[] = { 2, 1, 2 };
	cout<<getMaxArea_ref(test_case2,3)<<endl;
	return 0;
}

