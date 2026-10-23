/*
QUESTION:-

You are given the widths of n boxes. Arrange them in a pyramid made of levels.
Every level must have strictly more boxes than the level just above it, and
the total width of the boxes of a level must be strictly greater than the total
width of the level just above it. Each box can be used at most once, and it is
not necessary to use all the boxes. Find the maximum number of levels (the
height) of the pyramid.

Constraints:
1 <= n <= 100000
1 <= width <= 100000

Example 1:

Input:
boxes = [10,20,30,50,60,70]

Output:
3
(levels from the top: [10], [20,30], [50,60,70])

Example 2:

Input:
boxes = [40,100,20,30]

Output:
2
(levels: [20], [30,40])
*/

/*
APPROACH:-

-> Sort the boxes in increasing order. The top level should use the smallest box, because a small top makes it easy for every level below it to be bigger.
-> Build the levels one by one from the top. Keep the width and the number of boxes of the previous (finished) level.
-> Take the next boxes in sorted order into the current level, and stop as soon as the current level has strictly more boxes and strictly more total width than the previous level. Then the level is finished, and the height increases by one.
-> Taking the smallest possible boxes for every level leaves the bigger boxes for the later levels, which are the hardest ones to satisfy. That is why the greedy choice is safe.
-> If the boxes finish before the current level is complete, that level is thrown away.
-> Let N be the number of boxes. Sorting costs N * log N and one pass costs N, so the time is N * log N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxPyramidHeight(vector<int> &boxes)
{
    sort(boxes.begin(), boxes.end());

    int height = 1;
    int previousWidth = boxes[0];
    int previousCount = 1;
    int currentWidth = 0;
    int currentCount = 0;

    for (int i = 1; i < (int)boxes.size(); i++)
    {
        currentWidth += boxes[i];
        currentCount++;

        if (currentWidth > previousWidth && currentCount > previousCount)
        {
            previousWidth = currentWidth;
            previousCount = currentCount;
            currentWidth = 0;
            currentCount = 0;
            height++;
        }
    }

    return height;
}

int main()
{
    vector<int> boxes = {10, 20, 30, 50, 60, 70};

    cout << maxPyramidHeight(boxes) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
