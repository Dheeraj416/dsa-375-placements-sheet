/*
QUESTION:-

Given a string s, find the length of its longest repeating subsequence. A
repeating subsequence is a subsequence that appears twice in s, where the two
copies do not use the same index of s for the same letter (so the i-th letter
of one copy and the j-th letter of the other copy must come from different
positions, i != j).

Constraints:
1 <= s.length <= 1000
s contains only English letters.

Example 1:

Input:
s = "AABEBCDD"

Output:
3
("ABD" appears twice: positions 0, 2, 6 and positions 1, 4, 7)

Example 2:

Input:
s = "axxxy"

Output:
2
("xx" appears twice, using different x letters)
*/

/*
APPROACH:-

-> This is the longest common subsequence (LCS) of the string with itself, with one extra rule: a letter at index i can be matched with a letter at index j only if i != j.
-> Let dp[i][j] be the length of the answer for the first i letters of one copy and the first j letters of the other copy.
-> If the letters s[i - 1] and s[j - 1] are equal and i != j, we can match them, so dp[i][j] = 1 + dp[i - 1][j - 1].
-> Otherwise, we skip a letter from one copy or the other: dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]).
-> Row 0 and column 0 are 0, because an empty string has no subsequence. The answer is dp[n][n].
-> Let N be the length of the string. The table has (N + 1) * (N + 1) cells, each filled in constant time, so the time and the space are both N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main()
{
    string s = "AABEBCDD";

    cout << longestRepeatingSubsequence(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
