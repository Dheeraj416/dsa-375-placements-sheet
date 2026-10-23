/*
QUESTION:-

Given an integer array and a number k, return the k-th smallest element of the
array (in sorted order, not the k-th distinct element).

Constraints:
1 <= k <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [7,10,4,3,20,15]
k = 3

Output:
7
(the sorted array is [3,4,7,10,15,20])

Example 2:

Input:
arr = [7,10,4,20,15]
k = 4

Output:
15
*/

/*
APPROACH:-

-> We only need the k smallest numbers, not the whole sorted order. A max heap (priority queue) of size k keeps exactly the k smallest numbers seen so far.
-> The top of the max heap is the largest of those k numbers, which is the k-th smallest so far.
-> Go through the array and push every number into the heap. If the heap size becomes bigger than k, remove the top (the largest), because it cannot be among the k smallest.
-> After processing all numbers, the top of the heap is the k-th smallest element.
-> Let N be the size of the array. Each number needs one push and maybe one pop on a heap of size k, so the time is N * log K.
-> The heap holds at most k + 1 numbers, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> maxHeap;

    for (int x : arr)
    {
        maxHeap.push(x);

        if ((int)maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int answer = kthSmallest(arr, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
