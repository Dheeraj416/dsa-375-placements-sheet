/*
QUESTION:-

Given two strings text1 and text2, return the length of their longest common
subsequence. A subsequence is a sequence obtained by deleting some characters
(possibly none) without changing the order of the remaining characters. If
there is no common subsequence, return 0.

Constraints:
1 <= text1.length, text2.length <= 1000
Both strings contain only lowercase English letters.

Example 1:

Input:
text1 = "abcde"
text2 = "ace"

Output:
3
(the longest common subsequence is "ace")

Example 2:

Input:
text1 = "abc"
text2 = "def"

Output:
0
*/

/*
APPROACH:-

-> Let lcs[i][j] be the LCS length of the first i characters of text1 and the first j characters of text2. If either prefix is empty, the answer is 0.
-> Compare the last characters of the two prefixes, text1[i - 1] and text2[j - 1].
-> If they are equal, this character can be added to the best common subsequence of the two shorter prefixes: lcs[i][j] = 1 + lcs[i - 1][j - 1].
-> If they are different, at least one of them cannot be used, so we drop one character from either string and take the better result: lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]).
-> Each cell only needs the row above and the current row, so we keep just two rows instead of the whole table.
-> The answer is the last cell of the last row.
-> Let N and M be the lengths of the two strings. We fill N * M cells, so the time is N * M.
-> Two rows of M + 1 cells are stored, so the space is M.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<int> previousRow(m + 1, 0);
    vector<int> currentRow(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
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

    return previousRow[m];
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int answer = longestCommonSubsequence(text1, text2);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(M)
*/
