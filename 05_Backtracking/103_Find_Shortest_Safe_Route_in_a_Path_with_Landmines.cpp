/*
QUESTION:-

You are given a matrix of 1s and 0s where a 0 is a landmine. All the cells next
to a landmine (up, down, left and right) are also unsafe. Find the length of the
shortest safe route that starts from any safe cell of the first column and ends
at any safe cell of the last column. You can move to the four adjacent cells
and you can only step on safe cells. The length is the number of moves. If there
is no safe route, return -1.

Constraints:
1 <= rows, columns <= 100
matrix[i][j] is 0 (landmine) or 1

Example 1:

Input:
matrix =
1 0 1 1 1 1
1 1 1 1 1 1
0 1 1 1 1 0
1 1 1 1 0 1
1 1 1 1 1 1

Output:
9

Example 2:

Input:
matrix =
1 0 1
1 1 1
1 1 1

Output:
2
(walk along the last row)
*/

/*
APPROACH:-

-> First mark the unsafe cells. For every landmine, mark the landmine itself and its four neighbors as unsafe.
-> Now we need the shortest path in an unweighted grid, so we use BFS. Instead of starting from one source, start from all the safe cells of the first column at the same time: push all of them into the queue with distance 0 (multi-source BFS).
-> Pop a cell from the queue. If it is in the last column, BFS reaches cells in increasing order of distance, so this is the shortest route and we return its distance.
-> Otherwise try the four neighbors. A neighbor is added to the queue if it is inside the matrix, is safe and has not been visited yet. Its distance is the distance of the current cell plus 1.
-> If the queue becomes empty without reaching the last column, no safe route exists, so return -1.
-> Let R and C be the size of the matrix. Marking the unsafe cells and the BFS visit every cell a constant number of times, so the time is R * C.
-> The unsafe matrix, the distance matrix and the queue take R * C space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int shortestSafeRoute(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowMoves[4] = {1, -1, 0, 0};
    int colMoves[4] = {0, 0, 1, -1};

    vector<vector<int>> unsafe(rows, vector<int>(cols, 0));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
            {
                unsafe[row][col] = 1;

                for (int direction = 0; direction < 4; direction++)
                {
                    int nextRow = row + rowMoves[direction];
                    int nextCol = col + colMoves[direction];

                    if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols)
                    {
                        unsafe[nextRow][nextCol] = 1;
                    }
                }
            }
        }
    }

    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    queue<pair<int, int>> toVisit;

    for (int row = 0; row < rows; row++)
    {
        if (!unsafe[row][0])
        {
            distance[row][0] = 0;
            toVisit.push({row, 0});
        }
    }

    while (!toVisit.empty())
    {
        int row = toVisit.front().first;
        int col = toVisit.front().second;
        toVisit.pop();

        if (col == cols - 1)
        {
            return distance[row][col];
        }

        for (int direction = 0; direction < 4; direction++)
        {
            int nextRow = row + rowMoves[direction];
            int nextCol = col + colMoves[direction];

            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
            {
                continue;
            }

            if (unsafe[nextRow][nextCol] || distance[nextRow][nextCol] != -1)
            {
                continue;
            }

            distance[nextRow][nextCol] = distance[row][col] + 1;
            toVisit.push({nextRow, nextCol});
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}};

    int answer = shortestSafeRoute(matrix);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
