/*
QUESTION:-

Given a binary matrix (every cell is 0 or 1), find the largest rectangular
sub-matrix that contains an equal number of 1s and 0s. Return its area (the
number of cells), or 0 if there is no such sub-matrix.

Constraints:
1 <= rows, columns <= 100
matrix[i][j] is 0 or 1

Example 1:

Input:
matrix =
0 0 1 1
0 1 1 1
1 1 1 0

Output:
6

Example 2:

Input:
matrix =
1 1
1 1

Output:
0
(there is no 0 in the matrix, so no sub-matrix can have equal numbers of 1s and 0s)
*/

/*
APPROACH:-

-> Replace every 0 in the matrix by -1. A sub-matrix has equal numbers of 1s and 0s exactly when the sum of its new values is 0.
-> So the problem becomes "find the largest rectangular sub-matrix with sum 0", the same as the previous problem.
-> Fix a pair of rows, top and bottom, and add the rows from top to bottom column by column to get one number for every column.
-> For these numbers, find the longest block of neighbouring numbers with the sum 0. Keep a running (prefix) sum and a map from a prefix sum to the first index where it appeared. When a prefix sum appears again, the numbers between the two places add up to 0. Start the map with the sum 0 at index -1.
-> The area is the length of the block times the number of rows between top and bottom. Keep the largest area over all pairs of rows.
-> Let R be the number of rows and C the number of columns. There are about R * R pairs of rows and each takes C steps (with the average constant time of the hash map), so the time is R * R * C.
-> The column sums, the map and the changed copy of the matrix need R * C values, so the space is R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestZeroSumLength(vector<int> &values)
{
    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1;

    int prefix = 0;
    int longest = 0;

    for (int i = 0; i < (int)values.size(); i++)
    {
        prefix = prefix + values[i];

        if (firstIndex.count(prefix) == 1)
        {
            longest = max(longest, i - firstIndex[prefix]);
        }
        else
        {
            firstIndex[prefix] = i;
        }
    }

    return longest;
}

int largestEqualSubmatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> values = matrix;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (values[r][c] == 0)
            {
                values[r][c] = -1;
            }
        }
    }

    int best = 0;

    for (int top = 0; top < rows; top++)
    {
        vector<int> columnSum(cols, 0);

        for (int bottom = top; bottom < rows; bottom++)
        {
            for (int c = 0; c < cols; c++)
            {
                columnSum[c] = columnSum[c] + values[bottom][c];
            }

            int width = longestZeroSumLength(columnSum);
            best = max(best, width * (bottom - top + 1));
        }
    }

    return best;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 0}};

    cout << largestEqualSubmatrix(matrix) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * R * C)
SPACE COMPLEXITY = O(R * C)
*/
