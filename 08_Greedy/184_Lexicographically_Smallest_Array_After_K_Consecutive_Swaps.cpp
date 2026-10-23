/*
QUESTION:-

Given an array of distinct integers and a number k, find the lexicographically
smallest array that can be obtained by doing at most k swaps of adjacent
elements. Each swap exchanges two neighbouring elements.

Constraints:
1 <= n <= 100000
0 <= k <= 1000000000
All the elements are distinct.

Example 1:

Input:
arr = [7,6,9,2,1]
k = 3

Output:
[2,7,6,9,1]
(bring 2 to the front using 3 swaps)

Example 2:

Input:
arr = [4,3,2,1]
k = 2

Output:
[2,4,3,1]
*/

/*
APPROACH:-

-> A smaller array in dictionary order means the first position should hold the smallest value possible, then the second position, and so on.
-> Go through the positions i = 0, 1, 2, ... while swaps are left. The elements that can be brought to position i are within the next k positions (every step to the left costs one swap), i.e. positions i to min(i + k, n - 1).
-> Find the smallest element in that window and its position pos.
-> Bring it to position i by moving it left one step at a time (pos - i adjacent swaps). The elements between i and pos shift one place to the right. Subtract pos - i from k.
-> Continue with the next position. Stop when k becomes 0 or the array is finished.
-> Let N be the size of the array. Searching the window and moving the element each cost at most N for every position, so the time is N * N in the worst case.
-> Only the array itself is used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void smallestAfterSwaps(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n && k > 0; i++)
    {
        int last = min((long long)n - 1, (long long)i + k);
        int pos = i;

        for (int j = i + 1; j <= last; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }

        for (int j = pos; j > i; j--)
        {
            swap(arr[j], arr[j - 1]);
        }

        k -= pos - i;
    }
}

int main()
{
    vector<int> arr = {7, 6, 9, 2, 1};
    int k = 3;

    smallestAfterSwaps(arr, k);

    for (int i = 0; i < (int)arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(1)
*/
