/*
QUESTION:-

Given a matrix in which every row is sorted in increasing order, find an element
that is present in all the rows. If there are several common elements, return
the smallest one. If there is no common element, return -1.

Constraints:
1 <= rows, columns <= 500
-1000000 <= matrix[i][j] <= 1000000

Example 1:

Input:
matrix =
1 2 3 4 5
2 4 5 8 10
3 5 7 9 11
1 3 5 7 9

Output:
5

Example 2:

Input:
matrix =
1 2
3 4

Output:
-1
*/

/*
APPROACH:-

-> A value is common to all rows exactly when it appears in every one of the R rows. So count in how many different rows each value appears.
-> Use a hash map from value to row count. Go through every row. Because the row is sorted, equal values are next to each other, so skip a value if it equals the one before it in the same row. This way each row adds at most 1 to the count of a value.
-> After all rows are processed, scan the first row from left to right. The first value whose count equals the number of rows is common to all rows. Since the first row is sorted, this is the smallest common value.
-> If no value in the first row has the full count, return -1.
-> Let R and C be the number of rows and columns. Every cell is processed once with constant average time, so the time is R * C.
-> The map can hold up to R * C values, so the space is R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findCommonElement(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_map<int, int> rowCount;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (col > 0 && matrix[row][col] == matrix[row][col - 1])
            {
                continue;
            }
            rowCount[matrix[row][col]]++;
        }
    }

    for (int value : matrix[0])
    {
        if (rowCount[value] == rows)
        {
            return value;
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 5, 7, 9, 11}, {1, 3, 5, 7, 9}};

    int answer = findCommonElement(matrix);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
