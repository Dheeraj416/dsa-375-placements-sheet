/*
QUESTION:-

Given an array of integers and a number k, print the k largest elements of the
array in decreasing order.

Constraints:
1 <= k <= n <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [12,5,787,1,23]
k = 2

Output:
787 23

Example 2:

Input:
arr = [1,23,12,9,30,2,50]
k = 3

Output:
50 30 23
*/

/*
APPROACH:-

-> Keep a min heap (a priority queue where the smallest value is on the top) that holds at most k values: the k largest values seen so far.
-> For every element, push it into the heap. If the heap now has more than k values, remove the top (the smallest). The removed value cannot be one of the k largest.
-> After all the elements are processed, the heap holds exactly the k largest elements. Take them out one by one: they come out from the smallest to the largest.
-> Reverse the collected values to print them in decreasing order.
-> Let N be the size of the array. Each of the N elements is pushed once and removed at most once from a heap of size k, so the time is N * log K.
-> The heap holds at most k + 1 values, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        minHeap.push(arr[i]);

        if ((int)minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> arr = {12, 5, 787, 1, 23};
    int k = 2;

    vector<int> answer = kLargest(arr, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
