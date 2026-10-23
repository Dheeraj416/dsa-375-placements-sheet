/*
QUESTION:-

Given an array of intervals where intervals[i] = [start, end], merge all the
overlapping intervals and return an array of the non-overlapping intervals that
cover all the intervals in the input.

Constraints:
1 <= intervals.length <= 10000
0 <= start <= end <= 10000

Example 1:

Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]

Example 2:

Input:
intervals = [[1,4],[4,5]]

Output:
[[1,5]]
*/

/*
APPROACH:-

-> Sort the intervals by their starting point.
-> Put the first interval into the answer list.
-> For every next interval, compare its start with the end of the last interval in the answer.
-> If start <= last end, they overlap, so extend the last end to max(last end, current end).
-> Otherwise there is a gap, so push the current interval as a new interval.
-> Sorting guarantees that an interval can only overlap with the most recent merged interval.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;

    if (intervals.empty())
    {
        return merged;
    }

    sort(intervals.begin(), intervals.end());
    merged.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); i++)
    {
        if (intervals[i][0] <= merged.back()[1])
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> answer = mergeIntervals(intervals);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N)
SPACE COMPLEXITY = O(N)
*/
