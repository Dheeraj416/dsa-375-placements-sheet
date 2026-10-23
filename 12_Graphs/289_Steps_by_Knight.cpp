/*
QUESTION:-

A knight is placed on a square chessboard of size N x N. Given the position of
the knight and the position of a target square (both as (row, column) with the
rows and columns numbered from 1), find the minimum number of steps the knight
needs to reach the target. A knight moves in an L shape: two squares in one
direction and one square in the perpendicular direction.

Constraints:
1 <= N <= 1000
1 <= row, column <= N

Example 1:

Input:
N = 6
knight = (4, 5)
target = (1, 1)

Output:
3

Example 2:

Input:
N = 8
knight = (1, 1)
target = (8, 8)

Output:
6
*/

/*
APPROACH:-

-> Each move of the knight costs one step, so the shortest number of steps is found by BFS (breadth first search) on the squares of the board.
-> Start with the knight's square in a queue with distance 0, and mark it visited.
-> Take a square from the queue. If it is the target, its distance is the answer. Otherwise try all 8 knight moves. For every new square that is inside the board and not visited, mark it, set its distance to the current distance plus 1, and push it.
-> BFS reaches squares in the order of their distance, so the first time the target is reached, the distance is the minimum.
-> If the knight is already on the target the answer is 0.
-> Let N be the side of the board. There are N * N squares and 8 moves from each, so the time is N * N.
-> The visited table and the queue take N * N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int knightSteps(int n, int knightRow, int knightCol, int targetRow, int targetCol)
{
    int rowMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, -1));
    queue<pair<int, int>> pending;

    distance[knightRow][knightCol] = 0;
    pending.push({knightRow, knightCol});

    while (!pending.empty())
    {
        int r = pending.front().first;
        int c = pending.front().second;
        pending.pop();

        if (r == targetRow && c == targetCol)
        {
            return distance[r][c];
        }

        for (int d = 0; d < 8; d++)
        {
            int newRow = r + rowMove[d];
            int newCol = c + colMove[d];

            if (newRow >= 1 && newRow <= n && newCol >= 1 && newCol <= n && distance[newRow][newCol] == -1)
            {
                distance[newRow][newCol] = distance[r][c] + 1;
                pending.push({newRow, newCol});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 6;

    cout << knightSteps(n, 4, 5, 1, 1) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
