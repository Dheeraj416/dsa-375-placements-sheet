/*
QUESTION:-

Given an array of integers, find the minimum and the maximum element of the
array.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [3,5,4,1,9]

Output:
1 9
(the minimum is 1 and the maximum is 9)

Example 2:

Input:
arr = [22,14,8,17,35,3]

Output:
3 35
*/

/*
APPROACH:-

-> Keep two variables: smallest and largest. Start both with the first element of the array.
-> Go through the remaining elements one by one. If an element is smaller than smallest, update smallest. If it is larger than largest, update largest.
-> After one pass, smallest and largest hold the answer. We never need to sort the array.
-> Edge case: an array with one element has the same value as minimum and maximum, and the loop simply does nothing.
-> Let N be the size of the array. We look at every element once, so the time is N.
-> Only two extra variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinAndMax(vector<int> &arr)
{
    int smallest = arr[0];
    int largest = arr[0];

    for (int i = 1; i < (int)arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return {smallest, largest};
}

int main()
{
    vector<int> arr = {3, 5, 4, 1, 9};

    pair<int, int> answer = findMinAndMax(arr);

    cout << answer.first << " " << answer.second << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
