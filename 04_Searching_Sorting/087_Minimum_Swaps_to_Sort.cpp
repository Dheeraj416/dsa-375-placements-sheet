/*
QUESTION:-

Given an array of distinct integers, find the minimum number of swaps (of any
two elements, not necessarily adjacent) needed to sort the array in increasing
order.

Constraints:
1 <= arr.length <= 100000
1 <= arr[i] <= 1000000000
All the values are distinct.

Example 1:

Input:
arr = [4,3,2,1]

Output:
2
(swap 4 with 1, then swap 3 with 2)

Example 2:

Input:
arr = [1,5,4,3,2]

Output:
2
(swap 5 with 2, then swap 4 with 3)
*/

/*
APPROACH:-

-> Sort a copy of the array together with the original positions. After sorting, the element at sorted position i came from the original position items[i].second. This describes where every element has to go.
-> This movement splits into cycles: element at position i must go to some position, whose element must go to another position, and so on until we come back to i.
-> A cycle with L elements can be fixed with exactly L - 1 swaps, and we cannot do better because each swap can fix at most one element in a cycle.
-> So find all the cycles with a visited array. Positions that are already correct form a cycle of length 1 and cost 0 swaps.
-> The answer is the sum of (cycle length - 1) over all cycles.
-> Let N be the size of the array. Sorting costs N * log N and the cycle walk costs N, so the time is N * log N.
-> The sorted pairs and the visited array take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minSwapsToSort(vector<int> &arr)
{
    int n = arr.size();

    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        items.push_back({arr[i], i});
    }

    sort(items.begin(), items.end());

    vector<int> visited(n, 0);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || items[i].second == i)
        {
            continue;
        }

        int cycleLength = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = 1;
            j = items[j].second;
            cycleLength++;
        }

        swaps = swaps + (cycleLength - 1);
    }

    return swaps;
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};

    int answer = minSwapsToSort(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
