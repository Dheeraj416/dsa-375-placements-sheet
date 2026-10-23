/*
QUESTION:-

Given a text and a pattern, find all the positions (0-indexed) in the text where
the pattern occurs, using the Boyer-Moore algorithm with the bad character rule.
Print the positions in increasing order. If the pattern does not occur, print -1.

Constraints:
1 <= pattern.length <= text.length <= 100000
text and pattern contain printable ASCII characters.

Example 1:

Input:
text = "ABAAABCD"
pattern = "ABC"

Output:
4

Example 2:

Input:
text = "AABAACAADAABAABA"
pattern = "AABA"

Output:
0 9 12
*/

/*
APPROACH:-

-> Boyer-Moore compares the pattern with the text from the RIGHT end of the pattern, and after a mismatch it jumps ahead using the bad character rule.
-> Preprocessing: store lastOccurrence[c], the last index where character c appears in the pattern (or -1 if it does not appear).
-> Keep shift = the position of the pattern's start in the text. Compare from j = m - 1 down to 0 while pattern[j] equals text[shift + j].
-> If all characters match (j < 0), record shift. Then shift forward so the next character of the text after the match lines up with its last occurrence in the pattern: shift = shift + m - lastOccurrence[text[shift + m]], or simply shift + 1 if the match was at the very end.
-> If there is a mismatch at j, the bad character is text[shift + j]. Move the pattern so that its last occurrence of that character lines up with the bad character: shift = shift + max(1, j - lastOccurrence[bad character]). If the bad character is not in the pattern, we skip past it completely.
-> At the end, print the recorded positions, or -1 if there are none.
-> Let N be the text length and M the pattern length. The worst case is N * M, but on normal text the jumps skip many characters, so the typical time is close to N / M. We state the worst case: N * M.
-> The table has 256 cells, and the positions found take at most N space, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> boyerMooreSearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> lastOccurrence(256, -1);

    for (int i = 0; i < m; i++)
    {
        lastOccurrence[(unsigned char)pattern[i]] = i;
    }

    vector<int> positions;
    int shift = 0;

    while (shift <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
        {
            j--;
        }

        if (j < 0)
        {
            positions.push_back(shift);

            if (shift + m < n)
            {
                shift = shift + m - lastOccurrence[(unsigned char)text[shift + m]];
            }
            else
            {
                shift = shift + 1;
            }
        }
        else
        {
            shift = shift + max(1, j - lastOccurrence[(unsigned char)text[shift + j]]);
        }
    }

    return positions;
}

int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";

    vector<int> answer = boyerMooreSearch(text, pattern);

    if (answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int x : answer)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(N)
*/
