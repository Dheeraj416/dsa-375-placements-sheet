/*
QUESTION:-

Given a rope of length n, cut it into segments so that every segment has length
x, y or z, and the number of segments is as large as possible. Return that
maximum number of segments. If the rope cannot be cut in this way, return 0.

Constraints:
1 <= n, x, y, z <= 10000

Example 1:

Input:
n = 4, x = 2, y = 1, z = 1

Output:
4
(1 + 1 + 1 + 1)

Example 2:

Input:
n = 5, x = 5, y = 3, z = 2

Output:
2
(3 + 2)
*/

/*
APPROACH:-

-> Let dp[i] be the maximum number of segments for a rope of length i, or -1 if a rope of length i cannot be cut exactly into pieces of the allowed lengths.
-> dp[0] = 0, because a rope of length 0 needs no pieces. All the other values start at -1.
-> For a length i, try each allowed piece length c. If c is at most i and dp[i - c] is not -1, then we can cut one piece of length c and the rest of the rope in the best possible way, giving dp[i - c] + 1 pieces. Keep the maximum.
-> The answer is dp[n]. If it is -1, the rope cannot be cut, so we return 0.
-> There are only 3 piece lengths, so every value is filled with 3 checks and the time is n.
-> The table has n + 1 values, so the space is n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int x, int y, int z)
{
    int pieces[3] = {x, y, z};

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int length = 1; length <= n; length++)
    {
        for (int k = 0; k < 3; k++)
        {
            int c = pieces[k];

            if (c <= length && dp[length - c] != -1)
            {
                dp[length] = max(dp[length], dp[length - c] + 1);
            }
        }
    }

    if (dp[n] == -1)
    {
        return 0;
    }

    return dp[n];
}

int main()
{
    int n = 4;
    int x = 2;
    int y = 1;
    int z = 1;

    cout << maxCuts(n, x, y, z) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(n)
*/
