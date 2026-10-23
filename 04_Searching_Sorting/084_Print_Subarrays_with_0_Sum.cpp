/*
QUESTION:-

Given an array of integers, print all the subarrays whose sum is 0. For every
such subarray print its start index and end index (both included). Print the
subarrays in the order in which their end index grows (and for the same end
index, in the order of their start index as found). If there is no such
subarray, print -1.

Constraints:
1 <= arr.length <= 100000
-1000000 <= arr[i] <= 1000000

Example 1:

Input:
arr = [4,2,-3,1,6]

Output:
1 3
(the subarray [2,-3,1] has the sum 0)

Example 2:

Input:
arr = [6,3,-1,-3,4,-2,2,4,6,-12,-7]

Output:
2 4
2 6
5 6
6 9
0 10
*/

/*
APPROACH:-

-> Let prefix[i] be the sum of the elements from index 0 to i. The sum of the subarray from index s to e is prefix[e] - prefix[s - 1]. It is 0 exactly when the two prefix sums are equal.
-> Keep a hash map from a prefix sum to the list of indexes where this sum appeared. Put the sum 0 at index -1 at the start, to represent the empty prefix (this finds the subarrays that begin at index 0).
-> Go through the array and keep the running sum. For the current index e, every index s' stored for the same running sum gives a zero-sum subarray from s' + 1 to e. Print all of them.
-> Then add the current index e to the list of this running sum.
-> If nothing was printed after the pass, print -1.
-> Let N be the size of the array and K the number of zero-sum subarrays. Finding them costs N and printing costs K, so the time is N + K.
-> The map stores up to N prefix sums, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void printZeroSumSubarrays(vector<int> &arr)
{
    unordered_map<long long, vector<int>> positions;
    positions[0].push_back(-1);

    long long sum = 0;
    bool found = false;

    for (int end = 0; end < (int)arr.size(); end++)
    {
        sum = sum + arr[end];

        for (int previous : positions[sum])
        {
            cout << previous + 1 << " " << end << "\n";
            found = true;
        }

        positions[sum].push_back(end);
    }

    if (!found)
    {
        cout << -1 << "\n";
    }
}

int main()
{
    vector<int> arr = {4, 2, -3, 1, 6};

    printZeroSumSubarrays(arr);

    return 0;
}

/*
TIME COMPLEXITY = O(N + K)
SPACE COMPLEXITY = O(N)
*/
