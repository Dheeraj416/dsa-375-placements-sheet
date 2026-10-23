/*
QUESTION:-

Sort an array of integers in increasing order using the heap sort algorithm.

Constraints:
1 <= n <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [12,11,13,5,6,7]

Output:
5 6 7 11 12 13

Example 2:

Input:
arr = [4,10,3,5,1]

Output:
1 3 4 5 10
*/

/*
APPROACH:-

-> A max heap is a complete binary tree stored in an array, where every parent is not smaller than its children. For the index i, the children are at 2 * i + 1 and 2 * i + 2. The largest value is always at index 0.
-> heapify(arr, n, i) fixes the heap below the index i (when the two subtrees are already heaps): find the largest among the node and its two children. If a child is larger, swap it with the node and continue from that child's position. Otherwise stop.
-> Step 1: build the max heap. Call heapify for every non leaf node, from the last one (n / 2 - 1) down to 0.
-> Step 2: repeat for i from n - 1 down to 1: swap the root arr[0] (the largest value) with arr[i], so the largest values collect at the end of the array. The heap now has size i, so call heapify(arr, i, 0) to repair it.
-> After the loop the array is sorted in increasing order.
-> Let N be the size of the array. Building the heap costs N and each of the N - 1 repairs costs log N, so the time is N * log N.
-> The sorting is in place and heapify uses a loop, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    for (int i = 0; i < (int)arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
