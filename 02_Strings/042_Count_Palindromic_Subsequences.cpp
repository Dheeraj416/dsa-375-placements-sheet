/*
QUESTION:-

Given a string s, return the number of palindromic subsequences in it (not
necessarily distinct). A subsequence is formed by deleting some characters
without changing the order of the rest. Subsequences taken from different sets
of positions are counted separately, even if the characters are the same.

Constraints:
1 <= s.length <= 60
s contains lowercase English letters.

Example 1:

Input:
s = "aab"

Output:
4
("a" (first), "a" (second), "b", "aa")

Example 2:

Input:
s = "abcd"

Output:
4
("a", "b", "c", "d")
*/

/*
APPROACH:-

-> Let dp[i][j] be the number of palindromic subsequences inside the substring from index i to j.
-> A single character is a palindrome, so dp[i][i] = 1.
-> Take the substring i..j. The subsequences are those that skip s[i], plus those that skip s[j], but the ones that skip both were counted twice. So we start with dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1].
-> If s[i] equals s[j], we also get new palindromes: every palindrome inside i + 1..j - 1 can be wrapped by s[i] and s[j], and the pair "s[i] s[j]" alone is a palindrome too. That adds dp[i + 1][j - 1] + 1. Together the formula becomes dp[i + 1][j] + dp[i][j - 1] + 1.
-> Fill the table by increasing length of the substring (2, 3, ... N), so the smaller substrings are ready. Cells with i bigger than j stay 0.
-> The answer is dp[0][N - 1].
-> Let N be the length of the string. The table has N * N cells, so the time and the space are both N * N.
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

            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s = "aab";

    long long answer = countPalindromicSubsequences(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
