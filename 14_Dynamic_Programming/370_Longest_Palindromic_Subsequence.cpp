/*
QUESTION:-

Given a string s, return the length of the longest palindromic subsequence in s.
A subsequence is a sequence obtained by deleting some characters (possibly none)
without changing the order of the remaining characters. A palindrome reads the
same forwards and backwards.

Constraints:
1 <= s.length <= 1000
s contains only lowercase English letters.

Example 1:

Input:
s = "bbbab"

Output:
4
(the longest palindromic subsequence is "bbbb")

Example 2:

Input:
s = "cbbd"

Output:
2
(the longest palindromic subsequence is "bb")
*/

/*
APPROACH:-

-> A palindromic subsequence of s reads the same from both sides, so it is also a subsequence of the reversed string.
-> So the longest palindromic subsequence of s is the same as the longest common subsequence (LCS) of s and the reverse of s.
-> Build the reversed string, then compute the LCS of the two strings with DP.
-> Let lcs[i][j] be the LCS length of the first i characters of s and the first j characters of the reversed string. If the two characters match, lcs[i][j] = 1 + lcs[i - 1][j - 1], otherwise lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]).
-> Only the previous row is needed, so we keep two rows.
-> Let N be the length of the string. The table has N * N cells, so the time is N * N.
-> Two rows of N + 1 cells and the reversed string are stored, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s)
{
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    int n = s.size();

    vector<int> previousRow(n + 1, 0);
    vector<int> currentRow(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == reversed[j - 1])
            {
                currentRow[j] = 1 + previousRow[j - 1];
            }
            else
            {
                currentRow[j] = max(previousRow[j], currentRow[j - 1]);
            }
        }

        previousRow = currentRow;
    }

    return previousRow[n];
}

int main()
{
    string s = "bbbab";

    int answer = longestPalindromicSubsequence(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
