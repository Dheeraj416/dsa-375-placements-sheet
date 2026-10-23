/*
QUESTION:-

Given an N x N chessboard and a knight placed at the top left corner (0, 0),
find a sequence of moves of the knight so that it visits every square of the
board exactly once (a knight's tour). A knight moves in an L shape: two squares
in one direction and one square in the other direction. Print the board where
every square holds the number of the move in which the knight visited it (the
starting square is move 1). If no tour exists, print "No solution".

Constraints:
1 <= N <= 6

Example 1:

Input:
N = 5

Output:
1 6 15 10 21
14 9 20 5 16
19 2 7 22 11
8 13 24 17 4
25 18 3 12 23

Example 2:

Input:
N = 3

Output:
No solution
*/

/*
APPROACH:-

-> Use backtracking. Keep a board filled with -1 (not visited) and put move number 1 on the start square.
-> From the current square, try the 8 knight moves in a fixed order. A move is allowed if the new square is inside the board and not visited yet.
-> For an allowed move, write the next move number there and recursively try to continue the tour from the new square.
-> If the recursion reaches move number N * N, all the squares are visited, so return true.
-> If the recursive call fails, undo the move (set the square back to -1) and try the next of the 8 moves. If all the moves fail, return false, which makes the previous square try another move.
-> For some sizes (like 3 and 4) no tour exists from the corner, and then the search ends with false and we print "No solution".
-> Let N be the board size. The search tries up to 8 moves from each of the N * N squares, so the time is 8^(N * N) in the worst case (much faster in practice for small boards).
-> The board and the recursion take N * N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool tour(int row, int col, int moveNumber, int n, vector<vector<int>> &board)
{
    if (moveNumber > n * n)
    {
        return true;
    }

    int rowMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int colMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int direction = 0; direction < 8; direction++)
    {
        int nextRow = row + rowMoves[direction];
        int nextCol = col + colMoves[direction];

        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n)
        {
            continue;
        }

        if (board[nextRow][nextCol] != -1)
        {
            continue;
        }

        board[nextRow][nextCol] = moveNumber;

        if (tour(nextRow, nextCol, moveNumber + 1, n, board))
        {
            return true;
        }

        board[nextRow][nextCol] = -1;
    }

    return false;
}

int main()
{
    int n = 5;

    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 1;

    if (tour(0, 0, 2, n, board))
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << board[row][col] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No solution\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(8^(N * N))
SPACE COMPLEXITY = O(N * N)
*/
