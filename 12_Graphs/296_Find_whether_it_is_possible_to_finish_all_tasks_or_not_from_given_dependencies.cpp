/*
QUESTION:-

There are n tasks numbered from 0 to n - 1. You are given a list of
prerequisites, where [a, b] means that the task b must be finished before the
task a can be started. Return true if it is possible to finish all the tasks,
and false otherwise.

Constraints:
1 <= n <= 100000
0 <= number of prerequisites <= 100000

Example 1:

Input:
n = 4
prerequisites = [[1,0],[2,1],[3,2]]

Output:
true
(the order 0, 1, 2, 3 works)

Example 2:

Input:
n = 2
prerequisites = [[1,0],[0,1]]

Output:
false
(each task waits for the other one)
*/

/*
APPROACH:-

-> Make a directed graph with an edge b -> a for every prerequisite [a, b]. All the tasks can be finished exactly when this graph has no cycle.
-> Use Kahn's algorithm. Count the indegree of every task, and put all the tasks with indegree 0 in a queue (they have no prerequisite).
-> Take a task from the queue and count it as finished. For every task that was waiting for it, reduce its indegree by 1. When the indegree becomes 0, push the task.
-> If a cycle exists, the tasks on the cycle never reach indegree 0, so they are never finished.
-> So the answer is true exactly when the number of finished tasks equals n.
-> Let V be the number of tasks and E the number of prerequisites. Every task and prerequisite is handled once, so the time is V + E.
-> The graph, the indegree array and the queue take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < (int)prerequisites.size(); i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b].push_back(a);
        indegree[a]++;
    }

    queue<int> pending;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            pending.push(i);
        }
    }

    int finished = 0;

    while (!pending.empty())
    {
        int u = pending.front();
        pending.pop();
        finished++;

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i];
            indegree[v]--;

            if (indegree[v] == 0)
            {
                pending.push(v);
            }
        }
    }

    return finished == n;
}

int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    bool answer = canFinish(n, prerequisites);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
