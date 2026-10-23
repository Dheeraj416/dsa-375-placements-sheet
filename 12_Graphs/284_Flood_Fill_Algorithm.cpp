/*
QUESTION:-

An image is given as a 2D grid of integers, where every integer is the color of
a pixel. You are given a starting pixel (sr, sc) and a new color. Perform a
flood fill: change the color of the starting pixel and of every pixel that is
connected to it through up, down, left and right moves and has the same
original color, to the new color. Return the changed image.

Constraints:
1 <= rows, columns <= 50
0 <= color <= 65535

Example 1:

Input:
image =
1 1 1
1 1 0
1 0 1
sr = 1, sc = 1, newColor = 2

Output:
2 2 2
2 2 0
2 0 1

Example 2:

Input:
image =
0 0 0
0 0 0
sr = 0, sc = 0, newColor = 0

Output:
0 0 0
0 0 0
*/

/*
APPROACH:-

-> Remember the original color of the starting pixel. If it is already equal to the new color, there is nothing to do (and the fill would never stop if we did not check this), so return the image as it is.
-> Use DFS (depth first search) from the starting pixel. For a pixel, if it is outside the image, or its color is not the original color, return.
-> Otherwise set its color to the new color, and call the same function for the four neighbours.
-> Because the color is changed as soon as a pixel is visited, a pixel is never visited twice.
-> Let R and C be the number of rows and columns. Each pixel is changed at most once, so the time is R * C.
-> The recursion can go as deep as the number of pixels in the region, so the space is R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void fill(vector<vector<int>> &image, int row, int col, int oldColor, int newColor)
{
    int rows = image.size();
    int cols = image[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return;
    }

    if (image[row][col] != oldColor)
    {
        return;
    }

    image[row][col] = newColor;

    fill(image, row - 1, col, oldColor, newColor);
    fill(image, row + 1, col, oldColor, newColor);
    fill(image, row, col - 1, oldColor, newColor);
    fill(image, row, col + 1, oldColor, newColor);
}

void floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];

    if (oldColor == newColor)
    {
        return;
    }

    fill(image, sr, sc, oldColor, newColor);
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    floodFill(image, 1, 1, 2);

    for (int r = 0; r < (int)image.size(); r++)
    {
        for (int c = 0; c < (int)image[r].size(); c++)
        {
            cout << image[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
