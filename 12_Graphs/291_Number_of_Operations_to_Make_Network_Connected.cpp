/*
QUESTION:-

There are n computers numbered from 0 to n - 1 connected by cables. The cables
are given as a list of pairs, where [a, b] is a cable between the computers a
and b. In one operation you can take one cable between two directly connected
computers and place it between any two computers that are not directly connected.
Return the minimum number of operations needed to make all the computers
connected into one network. If it is not possible, return -1.

Constraints:
1 <= n <= 100000
1 <= number of cables <= 100000
There are no repeated cables.

Example 1:

Input:
n = 4
connections = [[0,1],[0,2],[1,2]]

Output:
1
(move the cable 1-2 to connect the computer 3)

Example 2:

Input:
n = 6
connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]

Output:
2

Example 3:

Input:
n = 6
connections = [[0,1],[0,2],[0,3],[1,2]]

Output:
-1
(only 4 cables, but at least 5 are needed)
*/

/*
APPROACH:-

-> To connect n computers we need at least n - 1 cables. If there are fewer cables, it is impossible, so return -1.
-> Otherwise it is always possible. Count the connected groups (components) of computers using a DSU (disjoint set union): start with n groups, and for every cable that joins two computers of different groups, merge the groups and reduce the number of groups by 1.
-> To connect c groups into one we need c - 1 cables moved. Cables that were not needed to connect anything (they form cycles) are the spare ones, and there are enough of them because we have at least n - 1 cables in total.
-> So the answer is (number of groups) - 1.
-> Let N be the number of computers and M the number of cables. Each DSU operation is almost constant time, so the time is N + M.
-> The parent array takes N space.
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

int makeConnected(int n, vector<vector<int>> &connections)
{
    if ((int)connections.size() < n - 1)
    {
        return -1;
    }

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int groups = n;

    for (int i = 0; i < (int)connections.size(); i++)
    {
        int a = findRoot(parent, connections[i][0]);
        int b = findRoot(parent, connections[i][1]);

        if (a != b)
        {
            parent[a] = b;
            groups--;
        }
    }

    return groups - 1;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};

    cout << makeConnected(n, connections) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(N)
*/
