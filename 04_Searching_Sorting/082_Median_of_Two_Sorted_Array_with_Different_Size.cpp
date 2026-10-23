/*
QUESTION:-

Given two sorted arrays first and second of sizes n and m, return the median of
the two sorted arrays. The overall run time complexity should be
O(log(min(n, m))).

Constraints:
0 <= n, m <= 1000 and n + m >= 1
-1000000 <= first[i], second[i] <= 1000000

Example 1:

Input:
first = [1,3], second = [2]

Output:
2.00000

Example 2:

Input:
first = [1,2], second = [3,4]

Output:
2.50000
*/

/*
APPROACH:-

-> Always binary search on the smaller array so the search range is as small as possible.
-> We want to cut both arrays so that the left parts together hold (n + m + 1) / 2 elements and every element on the left is not greater than every element on the right.
-> Choose cutFirst elements from the first array by binary search. Then cutSecond = (n + m + 1) / 2 - cutFirst.
-> Find the four border values: the last element on the left and the first element on the right of each cut. Use INT_MIN and INT_MAX when a side is empty.
-> The cut is correct when leftFirst <= rightSecond and leftSecond <= rightFirst.
-> If leftFirst is too big, move the cut in the first array to the left. Otherwise move it to the right.
-> For an odd total the median is the largest left value. For an even total it is the average of the largest left value and the smallest right value.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &first, vector<int> &second)
{
    if (first.size() > second.size())
    {
        return findMedianSortedArrays(second, first);
    }

    int n = (int)first.size();
    int m = (int)second.size();
    int low = 0;
    int high = n;
    int leftSize = (n + m + 1) / 2;

    while (low <= high)
    {
        int cutFirst = low + (high - low) / 2;
        int cutSecond = leftSize - cutFirst;

        int leftFirst = INT_MIN;
        int rightFirst = INT_MAX;
        int leftSecond = INT_MIN;
        int rightSecond = INT_MAX;

        if (cutFirst > 0)
        {
            leftFirst = first[cutFirst - 1];
        }

        if (cutFirst < n)
        {
            rightFirst = first[cutFirst];
        }

        if (cutSecond > 0)
        {
            leftSecond = second[cutSecond - 1];
        }

        if (cutSecond < m)
        {
            rightSecond = second[cutSecond];
        }

        if (leftFirst <= rightSecond && leftSecond <= rightFirst)
        {
            if ((n + m) % 2 == 1)
            {
                return max(leftFirst, leftSecond);
            }

            return (max(leftFirst, leftSecond) + min(rightFirst, rightSecond)) / 2.0;
        }
        else if (leftFirst > rightSecond)
        {
            high = cutFirst - 1;
        }
        else
        {
            low = cutFirst + 1;
        }
    }

    return 0.0;
}

int main()
{
    vector<int> first = {1, 3};
    vector<int> second = {2};

    double answer = findMedianSortedArrays(first, second);

    cout << fixed << setprecision(5) << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log(min(N, M)))
SPACE COMPLEXITY = O(1)
*/
