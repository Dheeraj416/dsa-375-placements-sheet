/*
QUESTION:-

Given a 2D board of letters and a word, check whether the word exists in the
board. The word is built from letters of sequentially adjacent cells (cells next
to each other horizontally or vertically). The same cell cannot be used more than
once in one word.

Constraints:
1 <= rows, columns <= 6
1 <= word.length <= 15
The board and the word contain uppercase and lowercase English letters.

Example 1:

Input:
board =
A B C E
S F C S
A D E E
word = "ABCCED"

Output:
true

Example 2:

Input:
board =
A B C E
S F C S
A D E E
word = "ABCB"

Output:
false
(the second B would need the same cell again)
*/

/*
APPROACH:-

-> Try every cell as the starting point of the word. From a cell, use DFS with backtracking to match the word letter by letter.
-> The DFS function gets the cell and the index of the letter we want to match. If the index equals the word length, every letter was matched, so return true.
-> If the cell is outside the board or its letter is different from word[index], return false.
-> Mark the current cell as used (replace its letter with '#') so it cannot be reused in the same path, and try the four neighbors with index + 1.
-> After the neighbors are tried, restore the letter (backtrack), because another path may use this cell later.
-> If any starting cell returns true, the word exists. If none does, return false.
-> Let R and C be the board size and L the length of the word. Each DFS branches into at most 3 directions after the first step, so the time is R * C * 3^L.
-> The recursion goes at most L deep, so the space is L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool searchFrom(int row, int col, int index, vector<vector<char>> &board, string &word)
{
    if (index == (int)word.size())
    {
        return true;
    }

    int rows = board.size();
    int cols = board[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return false;
    }

    if (board[row][col] != word[index])
    {
        return false;
    }

    char saved = board[row][col];
    board[row][col] = '#';

    bool found = searchFrom(row + 1, col, index + 1, board, word) ||
                 searchFrom(row - 1, col, index + 1, board, word) ||
                 searchFrom(row, col + 1, index + 1, board, word) ||
                 searchFrom(row, col - 1, index + 1, board, word);

    board[row][col] = saved;

    return found;
}

bool wordExists(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (searchFrom(row, col, 0, board, word))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    bool answer = wordExists(board, word);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C * 3^L)
SPACE COMPLEXITY = O(L)
*/
