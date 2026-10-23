/*
QUESTION:-

Given an array of integers, find the length of the longest alternating
subsequence. In an alternating subsequence the differences between neighbouring
elements are strictly positive and negative one after the other, so
x1 < x2 > x3 < x4 ... or x1 > x2 < x3 > x4 ...

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [1,5,4]

Output:
3

Example 2:

Input:
arr = [1,17,5,10,13,15,10,5,16,8]

Output:
7
(1, 17, 5, 15, 5, 16, 8)
*/

/*
APPROACH:-

-> Keep two numbers while going from left to right. up is the length of the longest alternating subsequence seen so far that ends with a rise (the last step goes up). down is the same for a subsequence that ends with a fall.
-> Both start at 1, because a single element is an alternating subsequence.
-> If the current element is greater than the previous one, it can extend a subsequence that ended with a fall, so up = down + 1.
-> If the current element is smaller than the previous one, it can extend a subsequence that ended with a rise, so down = up + 1.
-> If the two elements are equal, nothing changes.
-> The answer is the larger of up and down. Rising and falling steps between neighbours are enough, because skipping elements in the middle of a long rise or fall never loses a turning point.
-> Let N be the size of the array. We make one pass, so the time is N.
-> Only two variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestAlternating(vector<int> &arr)
{
    int n = arr.size();
    int up = 1;
    int down = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            up = down + 1;
        }
        else if (arr[i] < arr[i - 1])
        {
            down = up + 1;
        }
    }

    return max(up, down);
}

int main()
{
    vector<int> arr = {1, 5, 4};

    cout << longestAlternating(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
