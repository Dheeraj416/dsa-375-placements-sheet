/*
QUESTION:-

Given an array of non-negative integers, sort it in increasing order using
counting sort.

Constraints:
1 <= arr.length <= 100000
0 <= arr[i] <= 100000

Example 1:

Input:
arr = [4,2,2,8,3,3,1]

Output:
[1,2,2,3,3,4,8]

Example 2:

Input:
arr = [5,0,5,1]

Output:
[0,1,5,5]
*/

/*
APPROACH:-

-> Counting sort does not compare elements. It counts how many times each value appears and then rebuilds the array in order. It works well when the range of values is small.
-> Find the maximum value K in the array and make a count array of size K + 1, filled with 0.
-> Go through the array and increase count[x] for every element x.
-> Go through the values from 0 to K. For each value, write it into the answer count[value] times.
-> The values are written in increasing order, so the result is sorted. Equal elements stay together.
-> Let N be the size of the array and K the maximum value. Counting costs N and rebuilding costs N + K, so the time is N + K.
-> The count array takes K space and the answer takes N space, so the space is N + K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> &arr)
{
    int maxValue = *max_element(arr.begin(), arr.end());
    vector<int> count(maxValue + 1, 0);

    for (int x : arr)
    {
        count[x]++;
    }

    vector<int> sorted;

    for (int value = 0; value <= maxValue; value++)
    {
        for (int times = 0; times < count[value]; times++)
        {
            sorted.push_back(value);
        }
    }

    return sorted;
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    vector<int> answer = countingSort(arr);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + K)
SPACE COMPLEXITY = O(N + K)
*/
