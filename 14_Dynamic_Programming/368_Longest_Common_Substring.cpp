/*
QUESTION:-

Given two strings s1 and s2, return the length of their longest common substring.
A substring is a block of consecutive characters of a string.

Constraints:
1 <= s1.length, s2.length <= 1000
Both strings contain only English letters.

Example 1:

Input:
s1 = "ABCDGH", s2 = "ACDGHR"

Output:
4
("CDGH")

Example 2:

Input:
s1 = "ABC", s2 = "ACB"

Output:
1
(only single letters are common)
*/

/*
APPROACH:-

-> Let dp[i][j] be the length of the longest common substring that ends exactly at s1[i - 1] and s2[j - 1].
-> If the two characters are equal, the common substring can be extended by one, so dp[i][j] = dp[i - 1][j - 1] + 1.
-> If they are different, there is no common substring ending at these two positions, so dp[i][j] = 0. This is different from the longest common subsequence, where we would carry the best value forward, because here the characters must be next to each other.
-> The answer is the largest value that appears anywhere in the table.
-> Let N and M be the lengths of the two strings. The table has (N + 1) * (M + 1) cells, each filled in constant time, so the time and the space are both N * M.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int best = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                best = max(best, dp[i][j]);
            }
        }
    }

    return best;
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << longestCommonSubstring(s1, s2) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(N * M)
*/
