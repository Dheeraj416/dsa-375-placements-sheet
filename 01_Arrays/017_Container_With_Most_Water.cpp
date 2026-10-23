/*
QUESTION:-

You are given an array height of length n. There are n vertical lines, and the
i-th line has its two ends at (i, 0) and (i, height[i]). Choose two lines that,
together with the x-axis, form a container that holds the most water. Return the
maximum amount of water the container can store. The container cannot be tilted.

Constraints:
2 <= height.length <= 100000
0 <= height[i] <= 10000

Example 1:

Input:
height = [1,8,6,2,5,4,8,3,7]

Output:
49
(the lines at index 1 and index 8 give min(8, 7) * (8 - 1) = 49)

Example 2:

Input:
height = [1,1]

Output:
1
*/

/*
APPROACH:-

-> The water held by two lines at positions left and right is min(height[left], height[right]) * (right - left). The shorter line decides the height.
-> Start with the widest container: left = 0 and right = n - 1. Calculate its area and update the best answer.
-> Now move one pointer inwards. The width gets smaller, so the only chance to get a bigger area is a taller line. Moving the taller line can never help, because the shorter line still limits the height.
-> So always move the pointer that points to the shorter line.
-> Repeat until the pointers meet. The best area seen is the answer.
-> Let N be the size of the array. Each step moves one pointer, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxWaterContainer(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int best = 0;

    while (left < right)
    {
        int width = right - left;
        int shorter = min(height[left], height[right]);

        best = max(best, width * shorter);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return best;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int answer = maxWaterContainer(height);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
