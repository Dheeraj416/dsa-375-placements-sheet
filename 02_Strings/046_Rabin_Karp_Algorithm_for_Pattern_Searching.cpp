/*
QUESTION:-

Given a text string and a pattern string, find all the starting positions
(0 based) where the pattern occurs in the text, using the Rabin-Karp rolling
hash algorithm.

Constraints:
1 <= pattern.length <= text.length <= 100000
Both strings consist of lowercase English letters.

Example 1:

Input:
text = "ababcabcab", pattern = "abc"

Output:
[2,5]

Example 2:

Input:
text = "aaaaa", pattern = "aa"

Output:
[0,1,2,3]
*/

/*
APPROACH:-

-> Convert a string into a number (a hash) by treating its characters as digits of a number in base 256, taken modulo a large prime so that the number stays small.
-> Compute the hash of the pattern and the hash of the first window of the text that has the same length.
-> Slide the window one position to the right. Remove the contribution of the outgoing character, multiply by the base and add the incoming character. This update takes O(1) time.
-> If the hash of the window equals the hash of the pattern, compare the actual characters to rule out a hash collision, and then store the position.
-> If the hashes differ, the window cannot be equal to the pattern, so no character comparison is needed.
-> On average this takes O(N + M) time. In the worst case, when many hashes collide, it takes O(N * M).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(string &text, string &pattern)
{
    vector<int> positions;
    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m == 0 || m > n)
    {
        return positions;
    }

    long long base = 256;
    long long mod = 1000000007;
    long long highestPower = 1;

    for (int i = 1; i < m; i++)
    {
        highestPower = (highestPower * base) % mod;
    }

    long long patternHash = 0;
    long long windowHash = 0;

    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + (unsigned char)pattern[i]) % mod;
        windowHash = (windowHash * base + (unsigned char)text[i]) % mod;
    }

    for (int start = 0; start + m <= n; start++)
    {
        if (patternHash == windowHash)
        {
            if (text.compare(start, m, pattern) == 0)
            {
                positions.push_back(start);
            }
        }

        if (start + m < n)
        {
            long long outgoing = (unsigned char)text[start];
            long long incoming = (unsigned char)text[start + m];

            windowHash = (windowHash - outgoing * highestPower % mod + mod) % mod;
            windowHash = (windowHash * base + incoming) % mod;
        }
    }

    return positions;
}

int main()
{
    string text = "ababcabcab";
    string pattern = "abc";

    vector<int> answer = rabinKarp(text, pattern);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(1)
*/
