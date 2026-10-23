/*
QUESTION:-

The space agency has n astronauts numbered from 0 to n - 1. It is given a list of
pairs of astronauts who are from the same country. If a is from the same country
as b, and b is from the same country as c, then a and c are from the same
country too. The agency wants to choose two astronauts for a mission, and they
must be from different countries. Count the number of ways to choose such a pair
of astronauts.

Constraints:
2 <= n <= 100000
0 <= number of pairs <= 100000

Example 1:

Input:
n = 5
pairs = [[0,1],[2,3],[0,4]]

Output:
6
(the countries are {0,1,4} and {2,3}, and 3 * 2 = 6)

Example 2:

Input:
n = 4
pairs = [[0,2]]

Output:
5
(the countries are {0,2}, {1} and {3}: 6 pairs in total minus 1 pair from the same country)
*/

/*
APPROACH:-

-> Group the astronauts of the same country with a DSU (disjoint set union). Start with every astronaut in a group of its own, and merge the two groups of every given pair. Keep the size of every group.
-> The total number of ways to choose any 2 astronauts is n * (n - 1) / 2.
-> A pair is bad when both astronauts are from the same country. A country with s astronauts has s * (s - 1) / 2 bad pairs.
-> So the answer = total pairs - the sum of s * (s - 1) / 2 over all the countries.
-> Use long long because n * (n - 1) / 2 can be about 5 * 10^9.
-> Let N be the number of astronauts and P the number of pairs. Each DSU operation is almost constant time, so the time is N + P.
-> The parent and size arrays take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findRoot(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    parent[x] = findRoot(parent, parent[x]);
    return parent[x];
}

long long countPairs(int n, vector<vector<int>> &pairs)
{
    vector<int> parent(n);
    vector<int> size(n, 1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < (int)pairs.size(); i++)
    {
        int a = findRoot(parent, pairs[i][0]);
        int b = findRoot(parent, pairs[i][1]);

        if (a != b)
        {
            parent[a] = b;
            size[b] += size[a];
        }
    }

    long long total = (long long)n * (n - 1) / 2;

    for (int i = 0; i < n; i++)
    {
        if (findRoot(parent, i) == i)
        {
            total -= (long long)size[i] * (size[i] - 1) / 2;
        }
    }

    return total;
}

int main()
{
    int n = 5;
    vector<vector<int>> pairs = {{0, 1}, {2, 3}, {0, 4}};

    cout << countPairs(n, pairs) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + P)
SPACE COMPLEXITY = O(N)
*/
