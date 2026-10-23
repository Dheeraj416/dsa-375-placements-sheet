/*
QUESTION:-

Given a string s, find the length of the longest proper prefix of s which is
also a suffix of s. A proper prefix is a prefix that is not equal to the whole
string. If there is no such prefix, return 0.

Constraints:
1 <= s.length <= 100000
s contains lowercase English letters.

Example 1:

Input:
s = "abab"

Output:
2
("ab" is both a prefix and a suffix)

Example 2:

Input:
s = "abcde"

Output:
0
*/

/*
APPROACH:-

-> This is the "lps" array of the KMP algorithm. lps[i] is the length of the longest proper prefix of s[0..i] which is also a suffix of s[0..i]. The answer is lps[N - 1].
-> Fill lps from left to right and keep length = the current matched prefix length (it is the lps value of the previous position).
-> For position i, if s[i] equals s[length], the match grows: length = length + 1 and lps[i] = length.
-> If they differ and length is not 0, we fall back to the next best shorter border: length = lps[length - 1], and we try again with the same i.
-> If they differ and length is 0, there is no border here, so lps[i] = 0 and we move to the next position.
-> Falling back never makes length bigger than the total number of increases, so the whole work is linear.
-> Let N be the length of the string. The time is N.
-> The lps array has N cells, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int length = 0;
    int i = 1;

    while (i < n)
    {
        if (s[i] == s[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else if (length != 0)
        {
            length = lps[length - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }

    return lps[n - 1];
}

int main()
{
    string s = "abab";

    int answer = longestPrefixSuffix(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
