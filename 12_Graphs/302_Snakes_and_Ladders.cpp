/*
QUESTION:-

A board has the squares numbered from 1 to N. You start at square 1 and want to
reach square N. In one turn you throw a dice that shows a number from 1 to 6, and
move forward by that many squares (a move that goes beyond N is not allowed). If
you land on the bottom of a ladder, you climb to its top. If you land on the
head of a snake, you slide down to its tail. Find the minimum number of dice
throws needed to reach square N. If it is not possible, return -1.

Constraints:
2 <= N <= 1000
There is no ladder or snake on the squares 1 and N, and a square is the start of at most one jump.

Example 1:

Input:
N = 30
ladders = 3->22, 5->8, 11->26, 20->29
snakes = 27->1, 21->9, 17->4, 19->7

Output:
3
(throw 2 to reach 3 and climb to 22, throw 6 to reach 28, throw 2 to reach 30)

Example 2:

Input:
N = 10
ladders = none
snakes = none

Output:
2
(1 -> 7 -> 10)
*/

/*
APPROACH:-

-> Each throw is one step, and all the squares are like the vertices of a graph. From a square x there is an edge to x + 1, ..., x + 6 (if they are not above N). So the minimum number of throws is the shortest path from 1 to N, which BFS finds.
-> Keep an array jump of size N + 1 where jump[x] = x normally. For a ladder or a snake from a to b, set jump[a] = b. After landing on a square, we always follow its jump.
-> Run BFS from square 1 with distance 0. For a square x taken from the queue, try the squares x + d for d from 1 to 6. For each, take y = jump[x + d]. If y was not visited, set its distance to dist[x] + 1 and push it.
-> When the square N is reached, its distance is the answer. If the BFS ends without reaching N, return -1.
-> Let N be the number of squares. Each square is pushed once and tries 6 throws, so the time is N.
-> The distance array and the queue take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minimumThrows(int n, vector<vector<int>> &jumps)
{
    vector<int> jump(n + 1);
    for (int i = 0; i <= n; i++)
    {
        jump[i] = i;
    }

    for (int i = 0; i < (int)jumps.size(); i++)
    {
        jump[jumps[i][0]] = jumps[i][1];
    }

    vector<int> dist(n + 1, -1);
    queue<int> pending;

    dist[1] = 0;
    pending.push(1);

    while (!pending.empty())
    {
        int x = pending.front();
        pending.pop();

        if (x == n)
        {
            return dist[x];
        }

        for (int d = 1; d <= 6; d++)
        {
            if (x + d > n)
            {
                break;
            }

            int y = jump[x + d];

            if (dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                pending.push(y);
            }
        }
    }

    return -1;
}

int main()
{
    int n = 30;
    vector<vector<int>> jumps = {{3, 22}, {5, 8}, {11, 26}, {20, 29}, {27, 1}, {21, 9}, {17, 4}, {19, 7}};

    cout << minimumThrows(n, jumps) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
