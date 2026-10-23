/*
QUESTION:-

A robot is located at the top-left corner of an m x n grid. It can only move
either down or right at any point in time. The robot wants to reach the
bottom-right corner of the grid. Return the number of possible unique paths.

Constraints:
1 <= m, n <= 100
The answer fits in a 32-bit signed integer.

Example 1:

Input:
m = 3, n = 7

Output:
28

Example 2:

Input:
m = 3, n = 2

Output:
3
*/

/*
APPROACH:-

-> To reach the bottom-right corner the robot makes exactly (m - 1) down moves and (n - 1) right moves.
-> A path is just an arrangement of these moves, so the answer is C(m + n - 2, m - 1).
-> Compute the combination with a loop: result = result * (total - r + i) / i for i = 1 to r.
-> Use the smaller of (m - 1) and (n - 1) as r so the loop is short and the numbers stay small.
-> The division is always exact at each step because the intermediate value is itself a combination.
-> Use long long to avoid overflow in the multiplication.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int rows, int cols)
{
    int totalMoves = rows + cols - 2;
    int chosenMoves = min(rows - 1, cols - 1);
    long long paths = 1;

    for (int i = 1; i <= chosenMoves; i++)
    {
        paths = paths * (totalMoves - chosenMoves + i) / i;
    }

    return (int)paths;
}

int main()
{
    int rows = 3;
    int cols = 7;

    int answer = uniquePaths(rows, cols);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(min(M, N))
SPACE COMPLEXITY = O(1)
*/
