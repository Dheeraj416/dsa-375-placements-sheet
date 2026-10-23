/*
QUESTION:-

A postman has to walk along every road of a town at least once and return to the
starting point, and wants the shortest such walk. The town is a connected,
undirected, weighted graph with V junctions (numbered from 0) and a list of
roads (u, v, w). Find the minimum total length of such a closed walk (the Chinese
postman, or route inspection, problem).

Constraints:
2 <= V <= 15
1 <= number of roads <= 100
1 <= w <= 1000
The graph is connected.

Example 1:

Input:
V = 4
roads = (0,1,1), (1,2,2), (2,3,3), (3,0,4), (0,2,5)

Output:
18
(the roads add up to 15, and the junctions 0 and 2 have an odd number of roads, so the postman repeats the shortest path 0 -> 1 -> 2 of length 3)

Example 2:

Input:
V = 3
roads = (0,1,1), (1,2,2), (2,0,3)

Output:
6
(every junction has an even number of roads, so the walk is a circuit through every road once)
*/

/*
APPROACH:-

-> If every junction has an even number of roads, an Eulerian circuit exists: a closed walk that uses every road exactly once. The answer is just the sum of all the road lengths.
-> Otherwise some junctions have an odd degree. The number of odd junctions is always even. Each of them must be left once more than it is entered (or the reverse), so some roads have to be walked twice. The extra walking must pair up the odd junctions, and the cheapest way is to pair them so that the total of the shortest path distances between the pairs is minimum.
-> Compute the shortest distances between all the pairs of junctions with the Floyd-Warshall algorithm.
-> Find the minimum cost of pairing the odd junctions with a bitmask recursion: take the first odd junction that is not paired yet, try to pair it with every other unpaired odd junction, and add the shortest distance between them. Remember the answers for every mask.
-> The final answer is the sum of all the road lengths plus the minimum pairing cost.
-> Let V be the number of junctions and K the number of odd junctions (K <= V). Floyd-Warshall costs V * V * V and the pairing costs 2^K * K, so the time is V * V * V + 2^K * K.
-> The distance table takes V * V space, and the pairing table takes 2^K space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int pairingCost(vector<int> &odd, vector<vector<int>> &dist, vector<int> &memo, int mask)
{
    int k = odd.size();

    if (mask == (1 << k) - 1)
    {
        return 0;
    }

    if (memo[mask] != -1)
    {
        return memo[mask];
    }

    int first = 0;
    while (mask & (1 << first))
    {
        first++;
    }

    int best = 1000000000;

    for (int second = first + 1; second < k; second++)
    {
        if (mask & (1 << second))
        {
            continue;
        }

        int newMask = mask | (1 << first) | (1 << second);
        int cost = dist[odd[first]][odd[second]] + pairingCost(odd, dist, memo, newMask);
        best = min(best, cost);
    }

    memo[mask] = best;
    return best;
}

int chinesePostman(int v, vector<vector<int>> &roads)
{
    const int INF = 1000000000;
    vector<vector<int>> dist(v, vector<int>(v, INF));
    vector<int> degree(v, 0);
    int total = 0;

    for (int i = 0; i < v; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < (int)roads.size(); i++)
    {
        int a = roads[i][0];
        int b = roads[i][1];
        int w = roads[i][2];

        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
        degree[a]++;
        degree[b]++;
        total += w;
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<int> odd;
    for (int i = 0; i < v; i++)
    {
        if (degree[i] % 2 == 1)
        {
            odd.push_back(i);
        }
    }

    if (odd.empty())
    {
        return total;
    }

    vector<int> memo(1 << odd.size(), -1);

    return total + pairingCost(odd, dist, memo, 0);
}

int main()
{
    int v = 4;
    vector<vector<int>> roads = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 0, 4}, {0, 2, 5}};

    cout << chinesePostman(v, roads) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V * V * V + 2^K * K)
SPACE COMPLEXITY = O(V * V + 2^K)
*/
