/*
QUESTION:-

Given two numbers rows and cols, create and print a matrix of that size filled
with alternating rectangles of the characters 'X' and 'O'. The outermost
rectangle is made of 'X', the next rectangle inside it is made of 'O', then 'X'
again, and so on up to the center.

Constraints:
1 <= rows, cols <= 100

Example 1:

Input:
rows = 5
cols = 6

Output:
X X X X X X
X O O O O X
X O X X O X
X O O O O X
X X X X X X

Example 2:

Input:
rows = 3
cols = 3

Output:
X X X
X O X
X X X
*/

/*
APPROACH:-

-> The rectangles are layers around the center. A cell belongs to layer 0 if it is on the outer border, to layer 1 if it is on the border of the matrix without the outer ring, and so on.
-> The layer number of a cell (r, c) is its distance from the nearest border: min(r, c, rows - 1 - r, cols - 1 - c).
-> Even layers are written with 'X' and odd layers with 'O'. So the character of every cell can be decided directly from its layer number.
-> Fill the matrix cell by cell with this rule and print it.
-> Example 1: the cell (2, 2) has layer min(2, 2, 2, 3) = 2, which is even, so it is 'X'; the cell (2, 1) has layer 1, so it is 'O'.
-> Let R and C be the number of rows and columns. We fill each cell once, so the time is R * C.
-> The matrix itself is the output, so there is no extra space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> alternatingRectangles(int rows, int cols)
{
    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int layer = min(min(r, c), min(rows - 1 - r, cols - 1 - c));

            if (layer % 2 == 0)
            {
                grid[r][c] = 'X';
            }
            else
            {
                grid[r][c] = 'O';
            }
        }
    }

    return grid;
}

int main()
{
    int rows = 5;
    int cols = 6;

    vector<vector<char>> grid = alternatingRectangles(rows, cols);

    for (vector<char> &row : grid)
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
SPACE COMPLEXITY = O(1)
*/
