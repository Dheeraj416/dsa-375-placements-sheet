/*
QUESTION:-

Given a connected undirected graph with V vertices numbered 0 to V-1, stored as
an adjacency list adj, return the Breadth First Search (BFS) traversal of the
graph starting from vertex 0. Visit the neighbors of a vertex in the same order
in which they appear in its list.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph has no self loops and no repeated edges.

Example 1:

Input:
V = 5
adj = [[1,2,3],[0],[0,4],[0],[2]]

Output:
[0,1,2,3,4]

Example 2:

Input:
V = 5
adj = [[2,3,1],[0],[0,4],[0],[2]]

Output:
[0,2,3,1,4]
*/

/*
APPROACH:-

-> BFS visits the graph level by level, so use a queue (first in, first out).
-> Keep a visited array so that a vertex is never put in the queue twice.
-> Put vertex 0 in the queue and mark it visited.
-> Repeat while the queue is not empty: take the front vertex, add it to the answer, and look at all its neighbors in list order.
-> Every neighbor that is not visited yet is marked visited and pushed into the queue.
-> Marking a vertex as visited at the time we push it (not when we pop it) is what prevents duplicates.
-> Let E be the number of edges. Every vertex is processed once and every edge is checked twice, so the time is V + E.
-> The visited array and the queue take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);
    vector<int> order;
    queue<int> toVisit;

    toVisit.push(0);
    visited[0] = 1;

    while (!toVisit.empty())
    {
        int current = toVisit.front();
        toVisit.pop();
        order.push_back(current);

        for (int neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                toVisit.push(neighbor);
            }
        }
    }

    return order;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj = {{1, 2, 3}, {0}, {0, 4}, {0}, {2}};

    vector<int> answer = bfsOfGraph(vertices, adj);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
