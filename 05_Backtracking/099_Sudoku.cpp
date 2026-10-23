/*
QUESTION:-

Given a partially filled 9 x 9 Sudoku board, check whether the filled cells are
valid. Only the filled cells need to be checked (the board does not have to be
solvable). A board is valid if:
- every row has no repeated digit from 1 to 9,
- every column has no repeated digit from 1 to 9,
- every one of the nine 3 x 3 boxes has no repeated digit from 1 to 9.
The character '.' marks an empty cell.

Constraints:
board.length == 9 and board[i].length == 9
board[i][j] is a digit from '1' to '9' or '.'

Example 1:

Input:
board =
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
true

Example 2:

Input:
board = the same board, but the top left cell is 8 instead of 5

Output:
false
(the digit 8 now appears twice in the first column and in the first box)
*/

/*
APPROACH:-

-> We must make sure that no digit repeats in any row, any column and any 3 x 3 box.
-> Keep three tables of "seen" flags: rowSeen[9][10], colSeen[9][10] and boxSeen[9][10]. The entry rowSeen[r][d] tells whether the digit d was already seen in row r, and similarly for columns and boxes.
-> The box number of a cell (r, c) is (r / 3) * 3 + (c / 3), which gives the numbers 0 to 8.
-> Go through all 81 cells. Skip the empty ones. For a digit d, if it was already seen in its row, its column or its box, the board is invalid, so return false. Otherwise mark it as seen in all three tables.
-> If we finish all the cells without a conflict, the board is valid.
-> The board has a fixed size of 81 cells, so the time is constant (written as R * C for a board with R rows and C columns).
-> The three tables have a fixed size, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    int rowSeen[9][10] = {0};
    int colSeen[9][10] = {0};
    int boxSeen[9][10] = {0};

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                continue;
            }

            int digit = board[row][col] - '0';
            int box = (row / 3) * 3 + (col / 3);

            if (rowSeen[row][digit] || colSeen[col][digit] || boxSeen[box][digit])
            {
                return false;
            }

            rowSeen[row][digit] = 1;
            colSeen[col][digit] = 1;
            boxSeen[box][digit] = 1;
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

    bool answer = isValidSudoku(board);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
