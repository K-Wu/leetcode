//123. Best Time to Buy and Sell Stock III
// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit.You may complete at most two transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include<iostream>
#include<vector>
using namespace std;
int max3(int a, int b, int c) {
	int result = a;
	if (result < b) result = b;
	if (result < c) result = c;
	return result;
}
int max2(int a, int b) {
	return a > b ? a : b;
}
int min2(int a, int b) {
	return a < b ? a : b;
}
int maxProfit(vector<int>& prices) {
	int len = prices.size();
	if (len == 0)
		return 0;
	vector<int> min_beg(len ,-1);
	vector<int> prices_beg(len ,-1);
	vector<int> max_end(len ,-1);
	vector<int> prices_end(len ,-1);
	min_beg[0] = prices[0];
	prices_beg[0] = 0;
	max_end[len - 1] = prices[len - 1];
	prices_end[len - 1] = 0;
	for (int i = 1; i < len; i += 1) {
		prices_beg[i] = max2(prices_beg[i - 1], prices[i] - min_beg[i - 1]);//prices_beg–¥≥…prices
		min_beg[i] = min2(min_beg[i - 1], prices[i]);
	}
	for (int i = len - 2; i > -1; i -= 1) {
		prices_end[i] = max2(prices_end[i + 1], max_end[i + 1] - prices[i]);//prices_end–¥≥…prices
		max_end[i] = max2(prices[i], max_end[i + 1]);
	}
	int max_profit = 0;
	for (int i = 2; i < len - 1; i += 1) {
		max_profit = max2(prices_beg[i - 1] + prices_end[i], max_profit);
	}
	max_profit = max2(prices_beg[len-1], max_profit);
	return max_profit;
}
int main() {
	vector<int> param1 = { 1,4,6,0,3,2,1,3 };
	vector<int> param2 = { 4,3,2,1 };
	vector<int> param3 = { 5,3,9,15 };
	int res = maxProfit(param3);
	return 0;
}