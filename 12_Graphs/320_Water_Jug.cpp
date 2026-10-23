/*
QUESTION:-

You have two empty jugs with capacities m and n liters, and an unlimited water
supply. In one step you can do one of these operations: fill a jug completely,
empty a jug completely, or pour water from one jug into the other until the
first jug is empty or the second jug is full. Find the minimum number of steps
needed to get exactly d liters of water in one of the jugs. If it is not
possible, return -1.

Constraints:
1 <= m, n <= 1000
1 <= d <= 1000

Example 1:

Input:
m = 4, n = 3, d = 2

Output:
4
((0,0) -> (0,3) -> (3,0) -> (3,3) -> (4,2))

Example 2:

Input:
m = 2, n = 4, d = 3

Output:
-1
(both capacities are even, so only an even amount can be measured)
*/

/*
APPROACH:-

-> A state is a pair (a, b): the amount of water in the first jug and in the second jug. The start state is (0, 0). Every step moves from a state to another state, so the shortest sequence of steps is found by BFS on the states.
-> From (a, b) the six possible moves are: fill the first jug (m, b), fill the second jug (a, n), empty the first jug (0, b), empty the second jug (a, 0), pour the first jug into the second jug, and pour the second jug into the first jug. When pouring, the amount moved is min(a, n - b) from the first jug, or min(b, m - a) from the second jug.
-> Keep a set of the visited states, so a state is never expanded twice.
-> When a state has a == d or b == d, the current number of steps is the answer. If the BFS ends first, return -1.
-> There are (m + 1) * (n + 1) states and 6 moves from each, so the time is M * N where M and N are the capacities.
-> The visited set and the queue take M * N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int waterJugSteps(int m, int n, int d)
{
    set<pair<int, int>> visited;
    queue<pair<pair<int, int>, int>> pending;

    pending.push({{0, 0}, 0});
    visited.insert({0, 0});

    while (!pending.empty())
    {
        int a = pending.front().first.first;
        int b = pending.front().first.second;
        int steps = pending.front().second;
        pending.pop();

        if (a == d || b == d)
        {
            return steps;
        }

        int pourAB = min(a, n - b);
        int pourBA = min(b, m - a);

        vector<pair<int, int>> nextStates;
        nextStates.push_back({m, b});
        nextStates.push_back({a, n});
        nextStates.push_back({0, b});
        nextStates.push_back({a, 0});
        nextStates.push_back({a - pourAB, b + pourAB});
        nextStates.push_back({a + pourBA, b - pourBA});

        for (int i = 0; i < (int)nextStates.size(); i++)
        {
            if (visited.count(nextStates[i]) == 0)
            {
                visited.insert(nextStates[i]);
                pending.push({nextStates[i], steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int m = 4;
    int n = 3;
    int d = 2;

    cout << waterJugSteps(m, n, d) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(M * N)
SPACE COMPLEXITY = O(M * N)
*/
