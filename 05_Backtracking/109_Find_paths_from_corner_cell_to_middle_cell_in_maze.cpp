/*
QUESTION:-

You are given an N x N maze (N is odd) of positive integers. You start at the
top left corner. If you are at a cell with the number k, you must jump exactly
k cells in one of the four directions: right, down, left or up (you may not
leave the maze, and you may not visit a cell twice). Find a path from the top
left corner to the middle cell of the maze, and print it as a list of cells
(row, column). If no path exists, print "No path".

Constraints:
3 <= N <= 9 (N is odd)
1 <= maze[i][j] <= N

Example 1:

Input:
maze =
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2

Output:
(0,0) -> (0,2) -> (0,4) -> (2,4) -> (4,4) -> (4,2) -> (4,0) -> (2,0) -> (2,2)

Example 2:

Input:
maze =
3 2 4 1 1
1 3 1 2 1
1 4 4 1 2
1 4 1 1 2
1 4 1 2 1

Output:
(0,0) -> (0,3) -> (0,4) -> (1,4) -> (2,4) -> (4,4) -> (4,3) -> (2,3) -> (3,3) -> (3,4) -> (3,2) -> (2,2)
*/

/*
APPROACH:-

-> The middle cell is (N / 2, N / 2). We search for a path with DFS and backtracking.
-> The function visit(row, col) keeps the path in a list. It adds the current cell to the path and marks the cell as visited.
-> If the current cell is the middle cell, we have a complete path, so return true.
-> Otherwise let k be the number in the current cell. Try the four jumps in a fixed order: right (col + k), down (row + k), left (col - k) and up (row - k). A jump is allowed if it stays inside the maze and lands on a cell that is not visited.
-> If a recursive call returns true, return true immediately and keep the path. If all four jumps fail, remove the current cell from the path, unmark it (backtrack) and return false.
-> If the call for the corner returns false, no path exists.
-> Let N be the size of the maze. Each cell has 4 choices, and a cell can be on the path only once, so the time is 4^(N * N) in the worst case.
-> The visited matrix and the path take N * N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool visit(int row, int col, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<pair<int, int>> &path)
{
    int n = maze.size();

    visited[row][col] = 1;
    path.push_back({row, col});

    if (row == n / 2 && col == n / 2)
    {
        return true;
    }

    int jump = maze[row][col];
    int rowMoves[4] = {0, 1, 0, -1};
    int colMoves[4] = {1, 0, -1, 0};

    for (int direction = 0; direction < 4; direction++)
    {
        int nextRow = row + rowMoves[direction] * jump;
        int nextCol = col + colMoves[direction] * jump;

        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n)
        {
            continue;
        }

        if (visited[nextRow][nextCol])
        {
            continue;
        }

        if (visit(nextRow, nextCol, maze, visited, path))
        {
            return true;
        }
    }

    path.pop_back();
    visited[row][col] = 0;

    return false;
}

int main()
{
    vector<vector<int>> maze = {
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2}};

    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<pair<int, int>> path;

    if (visit(0, 0, maze, visited, path))
    {
        for (int i = 0; i < (int)path.size(); i++)
        {
            if (i > 0)
            {
                cout << " -> ";
            }
            cout << "(" << path[i].first << "," << path[i].second << ")";
        }
        cout << "\n";
    }
    else
    {
        cout << "No path\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(4^(N * N))
SPACE COMPLEXITY = O(N * N)
*/
