/*
QUESTION:-

The city of Byteland has N houses connected by N - 1 roads, so that there is
exactly one path between any two houses (the houses and the roads form a tree).
Bob always starts from house 1 and walks along the shortest path to a house y.
Oliver waits at a house x and wants to catch Bob. Oliver catches Bob only if Bob
must pass through house x on the way. For every query (x, y), print "YES" if
Oliver can catch Bob, and "NO" otherwise.

Constraints:
1 <= N <= 100000
1 <= number of queries <= 100000
1 <= x, y <= N

Example 1:

Input:
N = 9
roads = 1-2, 1-3, 2-6, 2-7, 6-9, 7-8, 3-4, 3-5
queries (x, y) = (2, 9), (3, 9), (1, 8), (7, 8), (4, 5)

Output:
YES
NO
YES
YES
NO

Example 2:

Input:
N = 3
roads = 1-2, 1-3
queries (x, y) = (2, 3), (1, 3)

Output:
NO
YES
*/

/*
APPROACH:-

-> Think of the tree as rooted at house 1. The path from house 1 to house y goes down through the ancestors of y. So house x is on this path exactly when x is an ancestor of y (or x == y).
-> To answer such questions fast, run one DFS from house 1 and note for every house the time tin when the DFS enters it and the time tout when the DFS leaves it (the timer goes up by one at every enter and every leave).
-> The DFS time interval of a house contains the intervals of all the houses in its subtree. So x is an ancestor of y exactly when tin[x] <= tin[y] and tout[y] <= tout[x].
-> Answer every query with this check in constant time.
-> Let N be the number of houses and Q the number of queries. The DFS costs N and the queries cost Q, so the time is N + Q.
-> The arrays and the recursion take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &tout, int &timer)
{
    tin[node] = timer;
    timer++;

    for (int i = 0; i < (int)graph[node].size(); i++)
    {
        int next = graph[node][i];

        if (next != parent)
        {
            dfs(next, node, graph, tin, tout, timer);
        }
    }

    tout[node] = timer;
    timer++;
}

int main()
{
    int n = 9;
    vector<vector<int>> roads = {{1, 2}, {1, 3}, {2, 6}, {2, 7}, {6, 9}, {7, 8}, {3, 4}, {3, 5}};
    vector<vector<int>> queries = {{2, 9}, {3, 9}, {1, 8}, {7, 8}, {4, 5}};

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < (int)roads.size(); i++)
    {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }

    vector<int> tin(n + 1, 0);
    vector<int> tout(n + 1, 0);
    int timer = 0;
    dfs(1, 0, graph, tin, tout, timer);

    for (int i = 0; i < (int)queries.size(); i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];

        if (tin[x] <= tin[y] && tout[y] <= tout[x])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N + Q)
SPACE COMPLEXITY = O(N)
*/
