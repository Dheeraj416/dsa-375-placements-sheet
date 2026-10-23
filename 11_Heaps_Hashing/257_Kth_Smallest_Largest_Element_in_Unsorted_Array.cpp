/*
QUESTION:-

Given an unsorted array of distinct integers and a number k, find the k-th
smallest element and the k-th largest element of the array. Print them
separated by a space.

Constraints:
1 <= k <= n <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [7,10,4,3,20,15]
k = 3

Output:
7 10
(the sorted array is 3 4 7 10 15 20)

Example 2:

Input:
arr = [7,10,4,3,20,15]
k = 4

Output:
10 7
*/

/*
APPROACH:-

-> For the k-th smallest element, keep a max heap that holds the k smallest values seen so far. For each element, push it, and if the heap has more than k values, remove the top (the largest of them). At the end the top of the heap is the largest among the k smallest, which is the k-th smallest.
-> For the k-th largest element, keep a min heap that holds the k largest values seen so far in the same way. At the end the top is the smallest among the k largest, which is the k-th largest.
-> Both heaps are filled in the same pass over the array.
-> Let N be the size of the array. Each element is pushed and removed at most once in heaps of size k, so the time is N * log K.
-> Each heap holds at most k + 1 values, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void findKth(vector<int> &arr, int k, int &kthSmallest, int &kthLargest)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        maxHeap.push(arr[i]);
        if ((int)maxHeap.size() > k)
        {
            maxHeap.pop();
        }

        minHeap.push(arr[i]);
        if ((int)minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    kthSmallest = maxHeap.top();
    kthLargest = minHeap.top();
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int kthSmallest = 0;
    int kthLargest = 0;
    findKth(arr, k, kthSmallest, kthLargest);

    cout << kthSmallest << " " << kthLargest << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
