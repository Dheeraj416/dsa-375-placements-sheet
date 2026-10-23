/*
QUESTION:-

You are given N stalls at positions given in an array stalls, and C aggressive
cows. Place all the cows in the stalls so that the minimum distance between any
two cows is as large as possible. Return that largest possible minimum
distance.

Constraints:
2 <= C <= N <= 100000
0 <= stalls[i] <= 1000000000

Example 1:

Input:
stalls = [1,2,4,8,9], C = 3

Output:
3
Explanation: Place the cows at positions 1, 4 and 8 (or 9).

Example 2:

Input:
stalls = [10,1,2,7,5], C = 3

Output:
4
Explanation: Place the cows at positions 1, 5 and 10.
*/

/*
APPROACH:-

-> Sort the stall positions first.
-> Binary search on the answer, the minimum distance. It lies between 1 and (last stall - first stall).
-> For a candidate distance, place the first cow in the first stall and then greedily place the next cow in the first stall that is at least that distance away from the previous cow.
-> If all C cows can be placed, the distance is possible, so remember it and try a larger distance.
-> If not all the cows fit, the distance is too large, so try a smaller one.
-> Feasibility is monotone: if a distance works, every smaller distance also works, which is what makes binary search valid.
-> Placing each cow as early as possible leaves the most room for the remaining cows.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int> &stalls, int cows, int distance)
{
    int placed = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < (int)stalls.size(); i++)
    {
        if (stalls[i] - lastPosition >= distance)
        {
            placed++;
            lastPosition = stalls[i];
        }
    }

    return placed >= cows;
}

int aggressiveCows(vector<int> &stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls[0];
    int best = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid))
        {
            best = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return best;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;

    int answer = aggressiveCows(stalls, cows);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N + N * log(MAXDISTANCE))
SPACE COMPLEXITY = O(1)
*/
