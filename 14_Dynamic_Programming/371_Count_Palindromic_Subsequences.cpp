/*
QUESTION:-

Given a string s, return the number of non-empty palindromic subsequences in it.
Subsequences are counted by their positions, so the same text taken from
different positions is counted separately.

Constraints:
1 <= s.length <= 50
s contains only lowercase English letters.
The answer fits in a 64-bit signed integer.

Example 1:

Input:
s = "aab"

Output:
4
("a" from position 0, "a" from position 1, "b", and "aa")

Example 2:

Input:
s = "abcd"

Output:
4
("a", "b", "c" and "d")
*/

/*
APPROACH:-

-> Let dp[i][j] be the number of non-empty palindromic subsequences inside the part of the string from index i to index j. A single character is a palindrome, so dp[i][i] = 1.
-> Take the part from i to j. Count the subsequences of s[i+1..j] and of s[i..j-1]: dp[i + 1][j] + dp[i][j - 1]. The subsequences that lie inside s[i+1..j-1] are counted in both, so subtract dp[i + 1][j - 1] once.
-> If s[i] is different from s[j], this is the answer: dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1].
-> If s[i] is equal to s[j], we also get new palindromes that use both ends: every palindrome inside s[i+1..j-1] can be wrapped with s[i] and s[j] (dp[i + 1][j - 1] of them), and the pair s[i] s[j] alone is one more. So we add dp[i + 1][j - 1] + 1.
-> Fill the table by the length of the part, from 2 up to n, so that the shorter parts are ready. Cells for an empty part (i > j) stay 0. The answer is dp[0][n - 1].
-> Let N be the length of the string. The table has N * N cells, each filled in constant time, so the time and the space are both N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countPalindromicSubsequences(string s)
{
    int n = s.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i + length - 1 < n; i++)
        {
            int j = i + length - 1;

            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];

            if (s[i] == s[j])
            {
                dp[i][j] = dp[i][j] + dp[i + 1][j - 1] + 1;
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s = "aab";

    cout << countPalindromicSubsequences(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
