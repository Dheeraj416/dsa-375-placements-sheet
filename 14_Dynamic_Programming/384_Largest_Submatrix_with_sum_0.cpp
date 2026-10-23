/*
QUESTION:-

Given a matrix of integers, find the largest rectangular sub-matrix whose sum of
elements is 0. Return its area (the number of cells), or 0 if there is no such
sub-matrix.

Constraints:
1 <= rows, columns <= 100
-1000 <= matrix[i][j] <= 1000

Example 1:

Input:
matrix =
1 2 3
-3 -2 -1
1 7 5

Output:
6
(the first two rows: 1 + 2 + 3 - 3 - 2 - 1 = 0)

Example 2:

Input:
matrix =
9 7 16 5
1 -6 -7 3
1 8 7 9
7 -2 0 10

Output:
6
(rows 1 to 3 and columns 1 to 2 have the sum -6 - 7 + 8 + 7 - 2 + 0 = 0)
*/

/*
APPROACH:-

-> Fix a pair of rows, top and bottom. Add the rows from top to bottom column by column, so we get one number for every column: the sum of that column between the two rows.
-> A rectangle between these rows is a block of neighbouring columns. Its sum is the sum of the numbers of those columns. So we need the longest block of neighbouring numbers with the sum 0.
-> To find it, keep the running (prefix) sum and a map from a prefix sum to the first index where it appeared. If the same prefix sum appears again at index i, the numbers between the two places add up to 0, and its length is i minus the first index. Start the map with the sum 0 at index -1.
-> The area of the best rectangle for these two rows is the length of the block times the number of rows between top and bottom.
-> Do this for every pair of rows and keep the largest area.
-> Let R be the number of rows and C the number of columns. There are about R * R pairs of rows and each takes C steps (with the average constant time of the hash map), so the time is R * R * C.
-> The column sums and the map need C values, so the space is C.
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

int largestZeroSumSubmatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int best = 0;

    for (int top = 0; top < rows; top++)
    {
        vector<int> columnSum(cols, 0);

        for (int bottom = top; bottom < rows; bottom++)
        {
            for (int c = 0; c < cols; c++)
            {
                columnSum[c] = columnSum[c] + matrix[bottom][c];
            }

            int width = longestZeroSumLength(columnSum);
            best = max(best, width * (bottom - top + 1));
        }
    }

    return best;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {-3, -2, -1}, {1, 7, 5}};

    cout << largestZeroSumSubmatrix(matrix) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * R * C)
SPACE COMPLEXITY = O(C)
*/
