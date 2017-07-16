//56. Merge Intervals 16ms 27.21%
// Given a collection of intervals, merge all overlapping intervals.
// 
// For example,
// Given[1, 3], [2, 6], [8, 10], [15, 18],
// return[1, 6], [8, 10], [15, 18].
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
int max(int a, int b) {
	return a > b ? a : b;
}

vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() == 0)
		return {};

	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start <b.start;});
	vector<Interval> result;
	result.push_back(*intervals.begin());
	for (int i = 1; i < intervals.size(); i += 1)
	{
		if (intervals.at(i).start > result.rbegin()->end)
			result.push_back(intervals.at(i));
		else 
            result.rbegin()->end = max(intervals.at(i).end, result.rbegin()->end);
	}
	return result;

}
int main() {
	vector<Interval> param1 = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18) };
	vector<Interval> result1 = merge(param1);


	return 0;
}