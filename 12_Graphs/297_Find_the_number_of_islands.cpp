/*
QUESTION:-

You are given a 2D grid of characters where '1' is land and '0' is water. Return
the number of islands. An island is a group of land cells connected horizontally
or vertically (up, down, left, right). The cells outside the grid are water.

Constraints:
1 <= rows, columns <= 300
grid[i][j] is '0' or '1'

Example 1:

Input:
grid =
11110
11010
11000
00000

Output:
1

Example 2:

Input:
grid =
11000
11000
00100
00011

Output:
3
*/

/*
APPROACH:-

-> Every island is one connected group of land cells, so we count how many times we start a fresh search on land that was not visited before.
-> Keep a visited matrix of the same size as the grid.
-> Go through every cell. If the cell is land and not visited, we found a new island, so increase the count.
-> Then run DFS from that cell to mark the whole island as visited: from a cell, move up, down, left and right.
-> The DFS stops when the cell is outside the grid, is water, or is already visited.
-> Because the whole island is marked visited, its other cells will never start another count.
-> Let R be the number of rows and C the number of columns. Every cell is visited a constant number of times, so the time is R * C.
-> The visited matrix takes R * C space (the recursion can also go that deep).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return;
    }

    if (grid[row][col] == '0' || visited[row][col])
    {
        return;
    }

    visited[row][col] = 1;

    dfs(row + 1, col, grid, visited);
    dfs(row - 1, col, grid, visited);
    dfs(row, col + 1, grid, visited);
    dfs(row, col - 1, grid, visited);
}

int numIslands(vector<vector<char>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int islands = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '1' && !visited[row][col])
            {
                islands++;
                dfs(row, col, grid, visited);
            }
        }
    }

    return islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    int answer = numIslands(grid);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
