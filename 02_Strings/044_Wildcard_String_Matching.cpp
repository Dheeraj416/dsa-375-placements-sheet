/*
QUESTION:-

Given a text and a pattern, check whether the pattern matches the whole text.
The pattern may contain two special characters: '?' matches exactly one
character, and '*' matches any sequence of characters (including an empty
sequence). Return true if the pattern matches the entire text, otherwise false.

Constraints:
0 <= text.length, pattern.length <= 2000
text contains lowercase English letters.
pattern contains lowercase English letters, '?' and '*'.

Example 1:

Input:
text = "baaabab"
pattern = "ba*a?"

Output:
true

Example 2:

Input:
text = "baaabab"
pattern = "a*ab"

Output:
false
*/

/*
APPROACH:-

-> Walk through the text with a pointer i and through the pattern with a pointer j.
-> If the pattern character is '?' or equal to the text character, they match, so move both pointers forward.
-> If the pattern character is '*', remember this position (starIndex = j) and the text position (matchIndex = i), and move only j forward. At first the star matches an empty sequence.
-> If the characters do not match but we have seen a star before, go back: let the star swallow one more text character. That means j = starIndex + 1, matchIndex = matchIndex + 1 and i = matchIndex.
-> If there is no star to go back to, the match fails, so return false.
-> After the text ends, the remaining pattern must contain only stars (they match empty). Skip those stars, and the match succeeds only if the whole pattern was used.
-> Let N be the length of the text and M the length of the pattern. In the worst case the star is extended for every text position and the rest of the pattern is rechecked, so the time is N * M.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    int starIndex = -1;
    int matchIndex = 0;

    while (i < n)
    {
        if (j < m && (pattern[j] == '?' || pattern[j] == text[i]))
        {
            i++;
            j++;
        }
        else if (j < m && pattern[j] == '*')
        {
            starIndex = j;
            matchIndex = i;
            j++;
        }
        else if (starIndex != -1)
        {
            j = starIndex + 1;
            matchIndex++;
            i = matchIndex;
        }
        else
        {
            return false;
        }
    }

    while (j < m && pattern[j] == '*')
    {
        j++;
    }

    return j == m;
}

int main()
{
    string text = "baaabab";
    string pattern = "ba*a?";

    bool answer = isMatch(text, pattern);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(1)
*/
