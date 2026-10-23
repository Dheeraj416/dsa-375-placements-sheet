/*
QUESTION:-

Given a binary matrix of 0s and 1s, find the area of the largest rectangle that
contains only 1s.

Constraints:
1 <= rows, columns <= 200
matrix[i][j] is 0 or 1

Example 1:

Input:
matrix =
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

Output:
8
(the rectangle formed by rows 1 and 2 and all four columns has area 2 * 4 = 8)

Example 2:

Input:
matrix =
1 0
1 1

Output:
2
*/

/*
APPROACH:-

-> Treat every row as the base of a histogram: heights[c] is the number of consecutive 1s going up from this row in column c. If the cell is 0, the height becomes 0.
-> For each row, update the heights (add 1 for a 1, reset to 0 for a 0). The largest rectangle with its bottom edge on this row is the largest rectangle in this histogram.
-> To find the largest rectangle in a histogram, use a stack of column indexes with increasing heights. When a column is lower than the one on the stack top, pop the top: its rectangle extends to the left until the new stack top and to the right until the current column, so its width is (current index - new top - 1), or the whole current index if the stack becomes empty.
-> A sentinel height of 0 after the last column pops everything left on the stack.
-> The answer is the best area over all rows.
-> Let R and C be the number of rows and columns. Each row takes C for the histogram, so the time is R * C.
-> The heights array and the stack take C space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleInHistogram(vector<int> &heights)
{
    int n = heights.size();
    stack<int> indexes;
    int best = 0;

    for (int i = 0; i <= n; i++)
    {
        int currentHeight = 0;

        if (i < n)
        {
            currentHeight = heights[i];
        }

        while (!indexes.empty() && heights[indexes.top()] >= currentHeight)
        {
            int height = heights[indexes.top()];
            indexes.pop();

            int width = i;

            if (!indexes.empty())
            {
                width = i - indexes.top() - 1;
            }

            best = max(best, height * width);
        }

        indexes.push(i);
    }

    return best;
}

int maximalRectangle(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);
    int best = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 1)
            {
                heights[col]++;
            }
            else
            {
                heights[col] = 0;
            }
        }

        best = max(best, largestRectangleInHistogram(heights));
    }

    return best;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    int answer = maximalRectangle(matrix);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(C)
*/
