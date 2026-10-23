/*
QUESTION:-

Given a string, remove the consecutive duplicate characters, so that no two
neighboring characters of the result are the same. Only characters that are
next to each other and equal are reduced to one character.

Constraints:
1 <= s.length <= 100000
s contains lowercase English letters.

Example 1:

Input:
s = "geeksforgeek"

Output:
geksforgek

Example 2:

Input:
s = "aabcca"

Output:
abca
(the last 'a' stays because it is not next to the first 'a')
*/

/*
APPROACH:-

-> Build the answer one character at a time in a result string.
-> Go through the input. If the result is empty or the current character is different from the last character of the result, append it. Otherwise skip it, because it repeats the character just before it.
-> Because we compare with the last character that was kept, a long run like "aaaa" is reduced to one "a".
-> Characters that are equal but not neighbors (like the two a's in "aabcca") are both kept, which matches the problem.
-> Let N be the length of the string. We look at every character once, so the time is N.
-> The result string can have up to N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacters(string s)
{
    string result = "";

    for (char c : s)
    {
        if (result.empty() || result.back() != c)
        {
            result.push_back(c);
        }
    }

    return result;
}

int main()
{
    string s = "geeksforgeek";

    string answer = removeConsecutiveCharacters(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
