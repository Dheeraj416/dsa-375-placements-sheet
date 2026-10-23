/*
QUESTION:-

Write a program to solve a Sudoku puzzle by filling the empty cells. Every
digit from 1 to 9 must appear exactly once in each row, each column and each of
the nine 3 x 3 boxes. The empty cells are marked with '.'. The puzzle is
guaranteed to have exactly one solution.

Constraints:
board.length == 9 and board[i].length == 9
board[i][j] is a digit from '1' to '9' or '.'

Example 1:

Input:
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Output:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

Example 2:

Input:
The solved board of Example 1 with the digits at (row 0, col 0), (row 4, col 4)
and (row 8, col 8) replaced by '.'

Output:
The solved board of Example 1, because every blank is the only missing digit of its row.
*/

/*
APPROACH:-

-> Scan the board for the first empty cell. If there is none, the board is completely filled, so the puzzle is solved.
-> For that cell try the digits '1' to '9' one by one.
-> A digit is safe if it does not already appear in the same row, the same column or the same 3 x 3 box.
-> Place a safe digit and recursively solve the rest of the board.
-> If the recursion fails, remove the digit (backtrack) and try the next one.
-> If no digit works, return false so that the previous cell changes its digit.
-> Let E be the number of empty cells. In the worst case 9 choices are tried for each of them, and the recursion goes E levels deep.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit)
        {
            return false;
        }

        if (board[i][col] == digit)
        {
            return false;
        }

        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;

        if (board[boxRow][boxCol] == digit)
        {
            return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char digit = '1'; digit <= '9'; digit++)
                {
                    if (isSafe(board, row, col, digit))
                    {
                        board[row][col] = digit;

                        if (solveSudoku(board))
                        {
                            return true;
                        }

                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(9^E)
SPACE COMPLEXITY = O(E)
*/
