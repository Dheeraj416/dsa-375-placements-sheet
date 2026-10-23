/*
QUESTION:-

A message made of letters is encoded into digits with this mapping: 'A' -> "1",
'B' -> "2", ..., 'Z' -> "26". Given a string s of digits, return the number of
ways to decode it. A decoding splits the string into parts, and every part must
be a number from 1 to 26 without a leading zero.

Constraints:
1 <= s.length <= 30
s contains only digits and may contain leading zeros.

Example 1:

Input:
s = "226"

Output:
3
("BZ" = 2,26 and "VF" = 22,6 and "BBF" = 2,2,6)

Example 2:

Input:
s = "06"

Output:
0
("06" cannot be decoded, because a part cannot start with 0)
*/

/*
APPROACH:-

-> Let ways[i] be the number of ways to decode the first i characters of s. ways[0] = 1 (the empty string has one way), and ways[1] is 1 if s[0] is not '0', otherwise 0.
-> For ways[i], look at the last part of the decoding. It can be one digit, s[i - 1]. This is valid when the digit is not '0', and then we add ways[i - 1].
-> The last part can also be two digits, s[i - 2] and s[i - 1]. This is valid when their number is between 10 and 26, and then we add ways[i - 2].
-> If neither is valid, ways[i] stays 0, and every longer prefix that depends only on it also gets 0.
-> The answer is ways[n].
-> Let N be the length of the string. We fill N values, each in constant time, so the time is N.
-> The ways array has N + 1 values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    int n = s.size();
    vector<int> ways(n + 1, 0);
    ways[0] = 1;

    if (s[0] != '0')
    {
        ways[1] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] != '0')
        {
            ways[i] = ways[i] + ways[i - 1];
        }

        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (twoDigits >= 10 && twoDigits <= 26)
        {
            ways[i] = ways[i] + ways[i - 2];
        }
    }

    return ways[n];
}

int main()
{
    string s = "226";

    cout << numDecodings(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
