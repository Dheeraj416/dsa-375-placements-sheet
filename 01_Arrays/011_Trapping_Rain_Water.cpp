/*
QUESTION:-

Given n non-negative integers representing an elevation map where the width of
every bar is 1, compute how much water it can trap after raining.

Constraints:
1 <= n <= 20000
0 <= height[i] <= 100000

Example 1:

Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6

Example 2:

Input:
height = [4,2,0,3,2,5]

Output:
9
*/

/*
APPROACH:-

-> The water above a bar is min(tallest bar on its left, tallest bar on its right) - height of the bar.
-> Use two pointers, left and right, and two variables leftMax and rightMax.
-> Always process the side with the smaller bar, because that side is limited by its own maximum.
-> If the current bar is higher than the maximum of its side, update that maximum, otherwise add maximum - height to the water.
-> Move the pointer of the processed side inward and repeat until the pointers meet.
-> The smaller side is safe to process since the other side has a bar at least as tall as it.
-> No extra arrays for prefix and suffix maximums are needed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<int> &height)
{
    int left = 0;
    int right = (int)height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                water += leftMax - height[left];
            }

            left++;
        }
        else
        {
            if (height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int answer = trapRainWater(height);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
