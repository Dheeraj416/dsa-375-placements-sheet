/*
QUESTION:-

Given a binary matrix, find the distance of the nearest cell having value 1 for
every cell. The distance between two cells (r1, c1) and (r2, c2) is
|r1 - r2| + |c1 - c2|. A cell that has value 1 has distance 0. The matrix has at
least one 1. Print the matrix of distances.

Constraints:
1 <= rows, columns <= 500
Every cell is 0 or 1, and there is at least one 1.

Example 1:

Input:
grid =
0 1 1 0
1 1 0 0
0 0 1 1

Output:
1 0 0 1
0 0 1 1
1 1 0 0

Example 2:

Input:
grid =
1 0 1
1 1 0
1 0 0

Output:
0 1 0
0 0 1
0 1 2
*/

/*
APPROACH:-

-> Do a multi source BFS (breadth first search), starting from all the cells with value 1 at the same time.
-> Make a distance matrix filled with -1 (not visited). Put every cell with value 1 in the queue with distance 0.
-> Take a cell from the queue and look at its four neighbours (up, down, left, right). If a neighbour is inside the matrix and still has distance -1, its distance is the distance of the current cell plus 1. Put it in the queue.
-> BFS reaches the cells in the order of their distance, so the first time a cell gets a distance, it is the shortest one.
-> Let R and C be the number of rows and columns. Every cell enters the queue once and has four neighbours, so the time is R * C.
-> The distance matrix and the queue take R * C space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearestOne(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> pending;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 1)
            {
                distance[r][c] = 0;
                pending.push({r, c});
            }
        }
    }

    int rowMove[4] = {-1, 1, 0, 0};
    int colMove[4] = {0, 0, -1, 1};

    while (!pending.empty())
    {
        int r = pending.front().first;
        int c = pending.front().second;
        pending.pop();

        for (int d = 0; d < 4; d++)
        {
            int newRow = r + rowMove[d];
            int newCol = c + colMove[d];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && distance[newRow][newCol] == -1)
            {
                distance[newRow][newCol] = distance[r][c] + 1;
                pending.push({newRow, newCol});
            }
        }
    }

    return distance;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};

    vector<vector<int>> result = nearestOne(grid);

    for (int r = 0; r < (int)result.size(); r++)
    {
        for (int c = 0; c < (int)result[r].size(); c++)
        {
            cout << result[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
