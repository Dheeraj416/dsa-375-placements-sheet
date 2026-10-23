/*
QUESTION:-

Given an array and a number k, find the number of distinct elements in every
window (contiguous block) of size k, moving from left to right.

Constraints:
1 <= k <= n <= 100000
1 <= arr[i] <= 100000

Example 1:

Input:
arr = [1,2,1,3,4,2,3]
k = 4

Output:
3 4 4 3

Example 2:

Input:
arr = [4,1,1]
k = 2

Output:
2 1
*/

/*
APPROACH:-

-> Use a hash map count that stores how many times every value occurs in the current window. The number of distinct elements is the size of the map (only values with a count above 0 are kept).
-> Fill the map with the first k elements and write down its size.
-> Slide the window one step at a time: add the new element on the right (increase its count), and remove the old element on the left (decrease its count, and erase the key when the count becomes 0).
-> After each step, the size of the map is the answer for the new window.
-> Let N be the size of the array. Each element is added once and removed once, so the time is N.
-> The map holds at most k values, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> distinctInWindows(vector<int> &arr, int k)
{
    unordered_map<int, int> count;
    vector<int> result;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        count[arr[i]]++;

        if (i >= k)
        {
            int oldValue = arr[i - k];
            count[oldValue]--;

            if (count[oldValue] == 0)
            {
                count.erase(oldValue);
            }
        }

        if (i >= k - 1)
        {
            result.push_back((int)count.size());
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> answer = distinctInWindows(arr, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(K)
*/
