/*
QUESTION:-

Given an array of positive integers, find the minimum number of merge operations
needed to make the array a palindrome. In one merge operation you can take two
adjacent elements and replace them with one element equal to their sum.

Constraints:
1 <= arr.length <= 100000
1 <= arr[i] <= 10000

Example 1:

Input:
arr = [11,14,15,99]

Output:
3
(merge 11 and 14, then 25 and 15, then 40 and 99 to get [139])

Example 2:

Input:
arr = [1,4,5,1]

Output:
1
(merge 4 and 5 to get [1,9,1])
*/

/*
APPROACH:-

-> Use two pointers, one at each end, and keep the current sum of the group at each pointer (leftSum and rightSum). At the beginning each group is a single element.
-> If leftSum and rightSum are equal, these two groups match, so move both pointers inwards and start new groups with the next elements.
-> If leftSum is smaller, merge the left group with the next element on its right: move left forward, add that element to leftSum and count one operation.
-> If rightSum is smaller, do the same on the right side: move right backward, add that element to rightSum and count one operation.
-> The smaller side is the only side that can grow towards a match, because all the numbers are positive. So this greedy choice is always right.
-> Stop when the pointers meet or cross. The count is the answer.
-> Let N be the size of the array. Each step moves a pointer, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minMergeOperations(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    long long leftSum = arr[left];
    long long rightSum = arr[right];
    int operations = 0;

    while (left < right)
    {
        if (leftSum == rightSum)
        {
            left++;
            right--;
            leftSum = arr[left];
            rightSum = arr[right];
        }
        else if (leftSum < rightSum)
        {
            left++;
            leftSum = leftSum + arr[left];
            operations++;
        }
        else
        {
            right--;
            rightSum = rightSum + arr[right];
            operations++;
        }
    }

    return operations;
}

int main()
{
    vector<int> arr = {11, 14, 15, 99};

    int answer = minMergeOperations(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
