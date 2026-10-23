/*
QUESTION:-

You are given N jobs. Every job has an id, a deadline and a profit. Every job
takes exactly one unit of time to finish and only one job can be done at a time.
A job gives its profit only if it is finished on or before its deadline (time
starts from 1). Find the number of jobs done and the maximum total profit.

Constraints:
1 <= N <= 100000
1 <= deadline <= N
1 <= profit <= 500

Example 1:

Input:
jobs (id, deadline, profit) = (1,4,20), (2,1,10), (3,1,40), (4,1,30)

Output:
2 60
Explanation: Do job 3 on day 1 and job 1 on day 4. The profit is 40 + 20 = 60.

Example 2:

Input:
jobs (id, deadline, profit) = (1,2,100), (2,1,19), (3,2,27), (4,1,25), (5,1,15)

Output:
2 127
*/

/*
APPROACH:-

-> Greedy idea: try the most profitable jobs first.
-> Sort the jobs in decreasing order of profit.
-> Keep an array slot where slot[day] tells whether that day is already taken.
-> For each job, look for a free day starting from its deadline and going backwards to day 1.
-> Doing the job as late as possible keeps the earlier days free for other jobs with smaller deadlines.
-> If a free day is found, take the job there, add its profit and increase the job count. Otherwise skip the job.
-> A job with higher profit is never worse to choose, so this gives the maximum profit.
-> Let D be the largest deadline. The slot array has D + 1 entries, and in the worst case every job scans up to D days.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compareByProfit(const Job &first, const Job &second)
{
    return first.profit > second.profit;
}

vector<int> jobSequencing(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareByProfit);

    int maxDeadline = 0;
    for (int i = 0; i < (int)jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> slot(maxDeadline + 1, -1);
    int jobCount = 0;
    int totalProfit = 0;

    for (int i = 0; i < (int)jobs.size(); i++)
    {
        for (int day = jobs[i].deadline; day > 0; day--)
        {
            if (slot[day] == -1)
            {
                slot[day] = jobs[i].id;
                jobCount++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {jobCount, totalProfit};
}

int main()
{
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};

    vector<int> answer = jobSequencing(jobs);

    cout << answer[0] << " " << answer[1] << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N + N * D)
SPACE COMPLEXITY = O(D)
*/
