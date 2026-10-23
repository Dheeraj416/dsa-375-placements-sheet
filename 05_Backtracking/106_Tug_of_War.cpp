/*
QUESTION:-

Given an array of n integers, divide it into two subsets of sizes floor(n / 2)
and ceil(n / 2) (every element goes to exactly one subset) so that the absolute
difference between the sums of the two subsets is as small as possible. Return
that minimum difference. The integers may be negative.

Constraints:
2 <= n <= 20
-1000 <= arr[i] <= 1000

Example 1:

Input:
arr = [3,4,5,-3,100,1,89,54,23,20]

Output:
0
(the subsets {4,100,1,23,20} and {3,5,-3,89,54} both have the sum 148)

Example 2:

Input:
arr = [23,45,-34,12,0,98,-99,4,189,-1,4]

Output:
1
(one subset has 5 elements and the other has 6 elements)
*/

/*
APPROACH:-

-> Let total be the sum of all the elements. If one subset has the sum s, the other has total - s, so the difference is |total - 2 * s|. We only need to choose the elements of the first subset.
-> Use backtracking. The function choose(index, chosenCount, currentSum) decides for each element whether it goes into the first subset or not. The first subset must have exactly n / 2 elements (the other subset gets the rest, which is n / 2 or n / 2 + 1 elements).
-> When chosenCount reaches n / 2, we have a full first subset, so update the best difference with |total - 2 * currentSum| and return.
-> Prune: if the elements left are fewer than the number we still need to choose, stop. If there is no element left to look at, stop.
-> For each element try both choices: include it (chosenCount + 1, add the value) and exclude it.
-> Let N be the number of elements. We try all the subsets of size N / 2, so the time is C(N, N / 2), which is about 2^N.
-> The recursion goes N levels deep, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void choose(int index, int chosenCount, int currentSum, int total, vector<int> &arr, int &bestDifference)
{
    int n = arr.size();
    int needed = n / 2;

    if (chosenCount == needed)
    {
        bestDifference = min(bestDifference, abs(total - 2 * currentSum));
        return;
    }

    if (index == n)
    {
        return;
    }

    if (n - index < needed - chosenCount)
    {
        return;
    }

    choose(index + 1, chosenCount + 1, currentSum + arr[index], total, arr, bestDifference);
    choose(index + 1, chosenCount, currentSum, total, arr, bestDifference);
}

int tugOfWar(vector<int> &arr)
{
    int total = 0;

    for (int x : arr)
    {
        total = total + x;
    }

    int bestDifference = INT_MAX;

    choose(0, 0, 0, total, arr, bestDifference);

    return bestDifference;
}

int main()
{
    vector<int> arr = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};

    int answer = tugOfWar(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^N)
SPACE COMPLEXITY = O(N)
*/
