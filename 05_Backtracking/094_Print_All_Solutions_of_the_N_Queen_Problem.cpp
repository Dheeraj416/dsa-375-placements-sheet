/*
QUESTION:-

Place n queens on an n x n chessboard so that no two queens attack each other
(no two queens share a row, a column or a diagonal). Return all the distinct
solutions. Every solution is a board where 'Q' marks a queen and '.' marks an
empty cell.

Constraints:
1 <= n <= 9

Example 1:

Input:
n = 4

Output:
[".Q..","...Q","Q...","..Q."]
["..Q.","Q...","...Q",".Q.."]

Example 2:

Input:
n = 1

Output:
["Q"]
*/

/*
APPROACH:-

-> Place the queens row by row. Each row gets exactly one queen, so only the column has to be chosen.
-> For the current row try every column and check if it is safe.
-> To check safety in O(1), keep three arrays: columnUsed, lowerDiagonalUsed (index row + col) and upperDiagonalUsed (index n - 1 + col - row).
-> If the cell is safe, place the queen, mark the three arrays and recurse to the next row.
-> After the recursion, remove the queen and unmark the arrays (backtrack).
-> When row equals n, all the queens are placed, so store the board.
-> The hash arrays make each safety check constant time instead of scanning the board.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void placeQueens(int row, int n, vector<string> &board, vector<int> &columnUsed, vector<int> &lowerDiagonalUsed, vector<int> &upperDiagonalUsed, vector<vector<string>> &answer)
{
    if (row == n)
    {
        answer.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (columnUsed[col] == 0 && lowerDiagonalUsed[row + col] == 0 && upperDiagonalUsed[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            columnUsed[col] = 1;
            lowerDiagonalUsed[row + col] = 1;
            upperDiagonalUsed[n - 1 + col - row] = 1;

            placeQueens(row + 1, n, board, columnUsed, lowerDiagonalUsed, upperDiagonalUsed, answer);

            board[row][col] = '.';
            columnUsed[col] = 0;
            lowerDiagonalUsed[row + col] = 0;
            upperDiagonalUsed[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> answer;
    vector<string> board(n, string(n, '.'));
    vector<int> columnUsed(n, 0);
    vector<int> lowerDiagonalUsed(2 * n - 1, 0);
    vector<int> upperDiagonalUsed(2 * n - 1, 0);

    placeQueens(0, n, board, columnUsed, lowerDiagonalUsed, upperDiagonalUsed, answer);

    return answer;
}

int main()
{
    int n = 4;

    vector<vector<string>> answer = solveNQueens(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N!)
SPACE COMPLEXITY = O(N * N)
*/
