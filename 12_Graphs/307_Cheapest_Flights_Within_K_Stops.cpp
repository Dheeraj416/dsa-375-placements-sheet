/*
QUESTION:-

There are n cities numbered from 0 to n - 1 and a list of flights, where a flight
[from, to, price] is a one way flight. Given a source city, a destination city
and a number k, find the cheapest price to travel from the source to the
destination with at most k stops in between. If there is no such route, return -1.

Constraints:
1 <= n <= 100
0 <= k < n
1 <= price <= 10000

Example 1:

Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0, dst = 3, k = 1

Output:
700
(the route 0 -> 1 -> 3 with one stop)

Example 2:

Input:
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0

Output:
500
(no stops are allowed, so only the direct flight can be used)
*/

/*
APPROACH:-

-> A route with at most k stops uses at most k + 1 flights. Use the Bellman-Ford idea, but run it for exactly k + 1 rounds, where round r finds the cheapest prices using at most r flights.
-> Keep an array price with the best known price to every city. Start with price[src] = 0 and a huge value for the others.
-> In every round, copy the array into a new array called next. For every flight (from, to, cost), if price[from] is not huge and price[from] + cost < next[to], update next[to]. After going over all the flights, replace price with next.
-> Reading from the old array and writing to the copy is important. Otherwise one round could use two flights in a row, which would allow more flights than the limit.
-> After k + 1 rounds, price[dst] is the answer, or -1 if it is still huge.
-> Let E be the number of flights. We make k + 1 rounds over E flights, so the time is K * E.
-> The price arrays take N space where N is the number of cities.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int cheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    const int INF = 1000000000;
    vector<int> price(n, INF);
    price[src] = 0;

    for (int round = 0; round <= k; round++)
    {
        vector<int> next = price;

        for (int i = 0; i < (int)flights.size(); i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];

            if (price[from] != INF && price[from] + cost < next[to])
            {
                next[to] = price[from] + cost;
            }
        }

        price = next;
    }

    if (price[dst] == INF)
    {
        return -1;
    }

    return price[dst];
}

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    cout << cheapestFlight(n, flights, 0, 3, 1) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(K * E)
SPACE COMPLEXITY = O(N)
*/
