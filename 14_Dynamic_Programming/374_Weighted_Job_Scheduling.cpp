/*
QUESTION:-

You are given N jobs. Each job has a start time, an end time and a profit. You can
do only one job at a time, and a job can start at the moment another job ends
(start time equal to the previous end time is allowed). Find the maximum total
profit you can earn by choosing jobs that do not overlap.

Constraints:
1 <= N <= 1000
1 <= start < end <= 100000
1 <= profit <= 10000

Example 1:

Input:
jobs (start, end, profit) =
[1,2,50], [3,5,20], [6,19,100], [2,100,200]

Output:
250
(do the jobs [1,2,50] and [2,100,200])

Example 2:

Input:
jobs (start, end, profit) =
[1,3,5], [2,5,6], [4,6,5], [6,7,4], [5,8,11], [7,9,2]

Output:
17
(do the jobs [2,5,6] and [5,8,11])
*/

/*
APPROACH:-

-> Sort the jobs by their end time. Then all the jobs that can come before a job are earlier in the sorted list.
-> Let dp[i] be the maximum profit when job i is the last job that we do. If we do only this job, the profit is its own profit.
-> Look at every earlier job j. If job j ends at or before job i starts, we can do job j first, giving dp[j] + profit of i. Keep the largest value in dp[i].
-> The answer is the largest value in the dp array, because the best schedule can end with any job.
-> Let N be the number of jobs. Sorting takes N * log(N) and the two loops take N * N, so the time is N * N.
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool compareByEnd(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int maxProfit(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end(), compareByEnd);

    int n = jobs.size();
    vector<int> dp(n, 0);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = jobs[i][2];

        for (int j = 0; j < i; j++)
        {
            if (jobs[j][1] <= jobs[i][0])
            {
                dp[i] = max(dp[i], dp[j] + jobs[i][2]);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> jobs = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};

    cout << maxProfit(jobs) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
