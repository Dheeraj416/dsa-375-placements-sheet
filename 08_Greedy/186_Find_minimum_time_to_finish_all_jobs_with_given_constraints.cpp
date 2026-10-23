/*
QUESTION:-

There are n jobs in a row, and job[i] is the amount of work needed for the
i-th job. You have k assistants. Every assistant is given a group of
consecutive jobs (jobs cannot be skipped or reordered, and a group may be
empty), and the assistants work at the same time. One unit of work takes t
units of time. Find the minimum time in which all the jobs can be finished.

Constraints:
1 <= n <= 100000
1 <= k <= n
1 <= job[i] <= 10000
1 <= t <= 1000

Example 1:

Input:
job = [10,7,8,12,6,8]
k = 4
t = 5

Output:
75
(groups [10], [7,8], [12], [6,8] have work 10, 15, 12, 14; the biggest is 15, and 15 * 5 = 75)

Example 2:

Input:
job = [4,5,10]
k = 2
t = 5

Output:
50
(groups [4,5] and [10] have work 9 and 10; the biggest is 10, and 10 * 5 = 50)
*/

/*
APPROACH:-

-> The total time is t times the work of the busiest assistant. So we want to split the jobs into at most k consecutive groups so that the largest group sum is as small as possible.
-> Use binary search on this largest group sum, called limit. The limit is at least the biggest single job and at most the sum of all jobs.
-> For a given limit, check if k assistants are enough: go through the jobs and keep adding to the current group. If adding a job would cross the limit, start a new group (a new assistant). If the number of groups used is more than k, the limit is too small.
-> If the limit works, try a smaller one (move high to limit). Otherwise try a bigger one (move low to limit + 1).
-> When low and high meet, that value is the smallest possible largest group sum. Multiply it by t.
-> Let N be the number of jobs and S the sum of all jobs. The binary search takes log S steps and each check costs N, so the time is N * log S.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<int> &job, int k, int limit)
{
    int assistants = 1;
    int currentWork = 0;

    for (int i = 0; i < (int)job.size(); i++)
    {
        if (currentWork + job[i] > limit)
        {
            assistants++;
            currentWork = job[i];
        }
        else
        {
            currentWork += job[i];
        }
    }

    return assistants <= k;
}

long long minimumTime(vector<int> &job, int k, int t)
{
    int low = 0;
    int high = 0;

    for (int i = 0; i < (int)job.size(); i++)
    {
        low = max(low, job[i]);
        high += job[i];
    }

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (canFinish(job, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (long long)low * t;
}

int main()
{
    vector<int> job = {10, 7, 8, 12, 6, 8};
    int k = 4;
    int t = 5;

    cout << minimumTime(job, k, t) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log S)
SPACE COMPLEXITY = O(1)
*/
