/*
QUESTION:-

A salesman has to visit n cities. The distance between every two cities is
given in a matrix, where dist[i][j] is the distance from the city i to the city
j. Starting from the city 0, the salesman must visit every other city exactly
once and then return to the city 0. Find the minimum total distance of such a
tour.

Constraints:
2 <= n <= 15
0 <= dist[i][j] <= 10000, and dist[i][i] = 0

Example 1:

Input:
dist =
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Output:
80
(the tour 0 -> 1 -> 3 -> 2 -> 0 has the length 10 + 25 + 30 + 15)

Example 2:

Input:
dist =
0 1 2
1 0 3
2 3 0

Output:
6
(the tour 0 -> 1 -> 2 -> 0 has the length 1 + 3 + 2)
*/

/*
APPROACH:-

-> Trying all the orders of the cities takes n! time, which is too slow. The Held-Karp dynamic programming method uses the fact that the best way to finish the tour depends only on which cities were visited and which city we are in now.
-> Let a bitmask say which cities are visited (bit i is 1 when the city i is visited). Let dp[mask][last] be the minimum distance of a path that starts at the city 0, visits exactly the cities in mask, and ends at the city last.
-> Start with dp[1][0] = 0 (only the city 0 is visited).
-> For each mask and each last city in it, try to go to a city next that is not in the mask: dp[mask | (1 << next)][next] = min(itself, dp[mask][last] + dist[last][next]).
-> At the end, the answer is the minimum over all the cities last (other than 0) of dp[all cities][last] + dist[last][0], which closes the tour.
-> Let N be the number of cities. There are 2^N * N states and each tries N moves, so the time is 2^N * N * N.
-> The table has 2^N * N cells, so the space is 2^N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int travellingSalesman(vector<vector<int>> &dist)
{
    int n = dist.size();
    const int INF = 1000000000;

    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int last = 0; last < n; last++)
        {
            if (dp[mask][last] == INF)
            {
                continue;
            }

            for (int next = 0; next < n; next++)
            {
                if (mask & (1 << next))
                {
                    continue;
                }

                int newMask = mask | (1 << next);
                int cost = dp[mask][last] + dist[last][next];

                if (cost < dp[newMask][next])
                {
                    dp[newMask][next] = cost;
                }
            }
        }
    }

    int full = (1 << n) - 1;
    int best = INF;

    for (int last = 1; last < n; last++)
    {
        if (dp[full][last] != INF)
        {
            best = min(best, dp[full][last] + dist[last][0]);
        }
    }

    return best;
}

int main()
{
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

    cout << travellingSalesman(dist) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^N * N * N)
SPACE COMPLEXITY = O(2^N * N)
*/
