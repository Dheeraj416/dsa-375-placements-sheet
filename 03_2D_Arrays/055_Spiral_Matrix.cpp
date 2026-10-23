/*
QUESTION:-

Given a matrix of R rows and C columns, return all its elements in spiral order,
starting from the top left corner and moving right, then down, then left, then
up, and so on towards the center.

Constraints:
1 <= R, C <= 10
-100 <= matrix[i][j] <= 100

Example 1:

Input:
matrix =
1 2 3
4 5 6
7 8 9

Output:
[1,2,3,6,9,8,7,4,5]

Example 2:

Input:
matrix =
1 2 3 4
5 6 7 8
9 10 11 12

Output:
[1,2,3,4,8,12,11,10,9,5,6,7]
*/

/*
APPROACH:-

-> Keep four borders: top, bottom, left and right. They describe the part of the matrix that is not visited yet.
-> Repeat while top <= bottom and left <= right: walk the top row from left to right, then move top down by one.
-> Walk the right column from top to bottom, then move right inwards by one.
-> If rows are still left (top <= bottom), walk the bottom row from right to left, then move bottom up by one.
-> If columns are still left (left <= right), walk the left column from bottom to top, then move left inwards by one.
-> The two checks before the last two walks are needed for matrices with a single remaining row or column, otherwise the same cells would be added twice.
-> Let R and C be the number of rows and columns. Each cell is visited once, so the time is R * C.
-> The output list holds all cells, and the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int col = left; col <= right; col++)
        {
            result.push_back(matrix[top][col]);
        }
        top++;

        for (int row = top; row <= bottom; row++)
        {
            result.push_back(matrix[row][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int col = right; col >= left; col--)
            {
                result.push_back(matrix[bottom][col]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
            {
                result.push_back(matrix[row][left]);
            }
            left++;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> answer = spiralOrder(matrix);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(1)
*/
