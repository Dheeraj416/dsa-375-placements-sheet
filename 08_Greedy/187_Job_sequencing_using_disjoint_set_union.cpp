/*
QUESTION:-

You are given n jobs. Every job has a deadline and a profit. A job takes one unit
of time, only one job can be done at a time, and a job earns its profit only if
it is finished on or before its deadline (time slots are 1, 2, 3, ...). Find the
number of jobs done and the maximum total profit. Use a disjoint set union
(DSU) to find free time slots quickly.

Constraints:
1 <= n <= 100000
1 <= deadline <= n
1 <= profit <= 1000

Example 1:

Input:
jobs (deadline, profit) = (4,20), (1,10), (1,40), (1,30)

Output:
2 60
(do the job with profit 40 in slot 1 and the job with profit 20 in slot 4)

Example 2:

Input:
jobs (deadline, profit) = (2,100), (1,19), (2,27), (1,25), (3,15)

Output:
3 142
(do the jobs with profit 27, 100 and 15 in slots 1, 2 and 3)
*/

/*
APPROACH:-

-> Greedy idea: handle the jobs in decreasing order of profit, and give every job the latest free time slot on or before its deadline. This keeps the earlier slots free for the other jobs.
-> To find the latest free slot fast, use a DSU where parent[x] points to the latest free slot that is at most x. Slot 0 means "no free slot".
-> At the start parent[x] = x for every x from 0 to the largest deadline.
-> For a job with deadline d, find slot = find(d). If slot is 0, no free slot is available, so skip the job. Otherwise do the job in that slot: add its profit, count it, and mark the slot used by setting parent[slot] = slot - 1.
-> The find function uses path compression, which makes the lookups almost constant time.
-> Let N be the number of jobs. Sorting costs N * log N and the DSU operations cost about N, so the time is N * log N.
-> The parent array takes N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool compareByProfit(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

int findSlot(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    parent[x] = findSlot(parent, parent[x]);
    return parent[x];
}

void jobSequencing(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareByProfit);

    int maxDeadline = 0;
    for (int i = 0; i < (int)jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int totalProfit = 0;

    for (int i = 0; i < (int)jobs.size(); i++)
    {
        int slot = findSlot(parent, jobs[i][0]);

        if (slot > 0)
        {
            count++;
            totalProfit += jobs[i][1];
            parent[slot] = slot - 1;
        }
    }

    cout << count << " " << totalProfit << "\n";
}

int main()
{
    vector<vector<int>> jobs = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};

    jobSequencing(jobs);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
