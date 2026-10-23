/*
QUESTION:-

You are given a matrix of 1s and 0s where 0 is a hurdle (a blocked cell), and
two cells: a source and a destination. Find the length of the longest possible
route from the source to the destination. In a route you can move to the four
adjacent cells (up, down, left, right), you cannot step on a hurdle, and you
cannot visit the same cell twice. The length is the number of moves. If the
destination cannot be reached, return -1.

Constraints:
1 <= rows, columns <= 10
matrix[i][j] is 0 or 1
The source and the destination cells are 1.

Example 1:

Input:
matrix =
1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1
source = (0,0)
destination = (1,7)

Output:
24

Example 2:

Input:
matrix =
1 0
1 1
source = (0,0)
destination = (1,1)

Output:
2
*/

/*
APPROACH:-

-> The shortest path can be found with BFS, but the longest simple path needs us to try all the paths, so we use DFS with backtracking.
-> Keep a visited matrix. From the current cell, mark it visited and try each of the four neighbors that are inside the matrix, are not hurdles and are not visited. The recursive call returns the longest route length from that neighbor to the destination (or -1 if there is none).
-> If the current cell is the destination, the route length from here is 0.
-> For each neighbor with a valid answer, the candidate is 1 + the answer of the neighbor. Keep the maximum candidate.
-> After trying all neighbors, unmark the current cell (backtrack), so other routes can use it.
-> If no neighbor can reach the destination, return -1.
-> Let R and C be the size of the matrix. In the worst case every simple path is tried, so the time is exponential: 3^(R * C).
-> The visited matrix and the recursion depth take R * C space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestRoute(int row, int col, int targetRow, int targetCol, vector<vector<int>> &matrix, vector<vector<int>> &visited)
{
    if (row == targetRow && col == targetCol)
    {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowMoves[4] = {1, -1, 0, 0};
    int colMoves[4] = {0, 0, 1, -1};

    visited[row][col] = 1;
    int best = -1;

    for (int direction = 0; direction < 4; direction++)
    {
        int nextRow = row + rowMoves[direction];
        int nextCol = col + colMoves[direction];

        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
        {
            continue;
        }

        if (matrix[nextRow][nextCol] == 0 || visited[nextRow][nextCol])
        {
            continue;
        }

        int length = longestRoute(nextRow, nextCol, targetRow, targetCol, matrix, visited);

        if (length != -1)
        {
            best = max(best, length + 1);
        }
    }

    visited[row][col] = 0;

    return best;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    vector<vector<int>> visited(3, vector<int>(10, 0));

    int answer = longestRoute(0, 0, 1, 7, matrix, visited);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(3^(R * C))
SPACE COMPLEXITY = O(R * C)
*/
