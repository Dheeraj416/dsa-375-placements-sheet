/*
QUESTION:-

There are n jobs numbered from 1 to n, and a list of dependencies. A dependency
(a, b) means that the job a must be completed before the job b can start. Every
job takes exactly 1 unit of time, and any number of jobs can run at the same
time as long as their dependencies are completed. The dependencies form a
directed acyclic graph (DAG). Find the minimum time in which every job can be
completed.

Constraints:
1 <= n <= 100000
0 <= number of dependencies <= 100000

Example 1:

Input:
n = 10
dependencies = (1,3), (1,4), (1,5), (2,3), (2,8), (2,9), (3,6), (4,6), (4,8), (5,8), (6,7), (7,8), (8,10)

Output:
1 1 2 2 2 3 4 5 2 6
(the minimum completion times of the jobs 1 to 10)

Example 2:

Input:
n = 3
dependencies = (1,2), (2,3)

Output:
1 2 3
*/

/*
APPROACH:-

-> A job without any dependency can start at time 0 and finishes at time 1. Any other job can start only after all its dependencies finish, so its finishing time is 1 + the largest finishing time among its dependencies.
-> Process the jobs in topological order (Kahn's algorithm) so that a job is handled only after all of its dependencies. Count the indegree of every job (the number of jobs it waits for).
-> Put all the jobs with indegree 0 in a queue and set their time to 1.
-> When a job u is taken from the queue, go through every job v that depends on u: set time[v] = max(time[v], time[u] + 1), and decrease the indegree of v. When the indegree of v becomes 0, all its dependencies are done, so push v.
-> At the end time[i] is the minimum completion time of the job i.
-> Let V be the number of jobs and E the number of dependencies. Each job and dependency is handled once, so the time is V + E.
-> The graph, the indegrees and the queue take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minimumTimes(int n, vector<vector<int>> &dependencies)
{
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> time(n + 1, 0);

    for (int i = 0; i < (int)dependencies.size(); i++)
    {
        graph[dependencies[i][0]].push_back(dependencies[i][1]);
        indegree[dependencies[i][1]]++;
    }

    queue<int> pending;
    for (int job = 1; job <= n; job++)
    {
        if (indegree[job] == 0)
        {
            time[job] = 1;
            pending.push(job);
        }
    }

    while (!pending.empty())
    {
        int u = pending.front();
        pending.pop();

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i];

            time[v] = max(time[v], time[u] + 1);
            indegree[v]--;

            if (indegree[v] == 0)
            {
                pending.push(v);
            }
        }
    }

    return time;
}

int main()
{
    int n = 10;
    vector<vector<int>> dependencies = {{1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 8}, {2, 9}, {3, 6}, {4, 6}, {4, 8}, {5, 8}, {6, 7}, {7, 8}, {8, 10}};

    vector<int> answer = minimumTimes(n, dependencies);

    for (int job = 1; job <= n; job++)
    {
        cout << answer[job] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
