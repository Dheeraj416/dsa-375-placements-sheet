/*
QUESTION:-

A rat starts at the top-left cell (0, 0) of an n x n maze and wants to reach the
bottom-right cell (n - 1, n - 1). In the maze a cell with value 1 is open and a
cell with value 0 is blocked. The rat can move Down (D), Left (L), Right (R) or
Up (U), and it cannot visit the same cell twice in one path. Return all the
possible paths as strings of moves in lexicographic order. If no path exists,
print -1.

Constraints:
2 <= n <= 5
0 <= maze[i][j] <= 1

Example 1:

Input:
maze = [[1,0,0,0],
        [1,1,0,1],
        [1,1,0,0],
        [0,1,1,1]]

Output:
DDRDRR DRDDRR

Example 2:

Input:
maze = [[1,0],
        [1,0]]

Output:
-1
*/

/*
APPROACH:-

-> Use backtracking (depth first search) starting from the cell (0, 0). A visited matrix remembers the cells on the current path.
-> If the rat reaches (n - 1, n - 1), store the current path string.
-> From the current cell try the four directions in the order D, L, R, U, which is alphabetical order.
-> Because the directions are tried alphabetically, the paths are found already in lexicographic order and no sorting is needed.
-> A move is allowed only if the new cell is inside the maze, open (value 1) and not visited on this path.
-> Mark the current cell visited before exploring and unmark it afterwards (backtrack), so that other paths can pass through it.
-> If the starting cell is blocked there is no path at all.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void findPaths(int row, int col, vector<vector<int>> &maze, vector<vector<int>> &visited, string &path, vector<string> &answer)
{
    int n = (int)maze.size();

    if (row == n - 1 && col == n - 1)
    {
        answer.push_back(path);
        return;
    }

    string directions = "DLRU";
    int rowChange[4] = {1, 0, 0, -1};
    int colChange[4] = {0, -1, 1, 0};

    visited[row][col] = 1;

    for (int d = 0; d < 4; d++)
    {
        int newRow = row + rowChange[d];
        int newCol = col + colChange[d];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && maze[newRow][newCol] == 1 && visited[newRow][newCol] == 0)
        {
            path.push_back(directions[d]);
            findPaths(newRow, newCol, maze, visited, path, answer);
            path.pop_back();
        }
    }

    visited[row][col] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = (int)maze.size();
    vector<string> answer;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";

    if (maze[0][0] == 1)
    {
        findPaths(0, 0, maze, visited, path, answer);
    }

    return answer;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> answer = ratInMaze(maze);

    if (answer.empty())
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = 0; i < (int)answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(4^(N * N))
SPACE COMPLEXITY = O(N * N)
*/
