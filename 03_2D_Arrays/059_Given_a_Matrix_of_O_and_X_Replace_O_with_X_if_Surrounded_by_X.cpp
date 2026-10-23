/*
QUESTION:-

Given a matrix whose cells are either 'O' or 'X', replace every 'O' with 'X' if
it is surrounded by 'X' on all four sides. An 'O' is surrounded if it (and the
group of 'O' cells connected to it up, down, left or right) cannot reach the
border of the matrix. 'O' cells that are connected to a border cell stay as
they are.

Constraints:
1 <= rows, columns <= 100
matrix[i][j] is 'O' or 'X'

Example 1:

Input:
matrix =
X O X X X X
X O X X O X
X X X O O X
O X X X X X
X X X O X O
O O X O O O

Output:
X O X X X X
X O X X X X
X X X X X X
O X X X X X
X X X O X O
O O X O O O

Example 2:

Input:
matrix =
X X X
X O X
X X X

Output:
X X X
X X X
X X X
*/

/*
APPROACH:-

-> An 'O' cannot be captured if it is connected to the border. So instead of finding the surrounded cells, find the safe cells and capture everything else.
-> Run DFS from every 'O' that lies on the border of the matrix. Mark all the 'O' cells reached as safe (a visited matrix works).
-> After that, go through the whole matrix. A cell that is 'O' and not marked safe is surrounded, so change it to 'X'.
-> Cells that are marked safe, and cells that are 'X', stay unchanged.
-> Let R and C be the number of rows and columns. Every cell is visited a constant number of times, so the time is R * C.
-> The safe matrix and the recursion stack take R * C space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void markSafe(int row, int col, vector<vector<char>> &matrix, vector<vector<int>> &safe)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return;
    }

    if (matrix[row][col] != 'O' || safe[row][col])
    {
        return;
    }

    safe[row][col] = 1;

    markSafe(row + 1, col, matrix, safe);
    markSafe(row - 1, col, matrix, safe);
    markSafe(row, col + 1, matrix, safe);
    markSafe(row, col - 1, matrix, safe);
}

void replaceSurrounded(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> safe(rows, vector<int>(cols, 0));

    for (int row = 0; row < rows; row++)
    {
        markSafe(row, 0, matrix, safe);
        markSafe(row, cols - 1, matrix, safe);
    }

    for (int col = 0; col < cols; col++)
    {
        markSafe(0, col, matrix, safe);
        markSafe(rows - 1, col, matrix, safe);
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 'O' && !safe[row][col])
            {
                matrix[row][col] = 'X';
            }
        }
    }
}

int main()
{
    vector<vector<char>> matrix = {
        {'X', 'O', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'O', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'}};

    replaceSurrounded(matrix);

    for (vector<char> &row : matrix)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
