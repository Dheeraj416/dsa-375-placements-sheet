/*
QUESTION:-

You are given an m x n grid where every cell has one of three values: 0 is an
empty cell, 1 is a fresh orange and 2 is a rotten orange. Every minute, any
fresh orange that is directly adjacent (up, down, left or right) to a rotten
orange becomes rotten. Return the minimum number of minutes that must pass
until no cell has a fresh orange. If this is impossible, return -1.

Constraints:
1 <= m, n <= 10
grid[i][j] is 0, 1 or 2

Example 1:

Input:
grid = [[2,1,1],[1,1,0],[0,1,1]]

Output:
4

Example 2:

Input:
grid = [[2,1,1],[0,1,1],[1,0,1]]

Output:
-1
Explanation: The orange in the bottom left corner is never reached.
*/

/*
APPROACH:-

-> Use multi-source BFS (breadth first search). All the rotten oranges rot their neighbours at the same time, so they all start in the queue together.
-> First scan the grid: push every rotten orange into the queue and count the fresh oranges.
-> Process the queue level by level. One level is one minute: every orange taken from the queue rots its fresh neighbours, which are pushed for the next level.
-> Decrease the fresh counter every time an orange rots, and mark it as 2 so it is not visited twice.
-> Increase the minutes after finishing each level that was processed.
-> Stop when the queue is empty or no fresh oranges remain. If fresh oranges are still left, they are unreachable, so return -1.
-> If there were no fresh oranges at the start the answer is 0.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    queue<pair<int, int>> rotten;
    int fresh = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    int rowChange[4] = {-1, 1, 0, 0};
    int colChange[4] = {0, 0, -1, 1};
    int minutes = 0;

    while (!rotten.empty() && fresh > 0)
    {
        int levelSize = (int)rotten.size();

        for (int step = 0; step < levelSize; step++)
        {
            pair<int, int> cell = rotten.front();
            rotten.pop();

            for (int d = 0; d < 4; d++)
            {
                int newRow = cell.first + rowChange[d];
                int newCol = cell.second + colChange[d];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1)
                {
                    grid[newRow][newCol] = 2;
                    fresh--;
                    rotten.push({newRow, newCol});
                }
            }
        }

        minutes++;
    }

    if (fresh > 0)
    {
        return -1;
    }

    return minutes;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    int answer = orangesRotting(grid);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(M * N)
SPACE COMPLEXITY = O(M * N)
*/
