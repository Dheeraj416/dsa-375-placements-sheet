/*
QUESTION:-

Given a string s, return the number of palindromic substrings in it. A substring
is a contiguous sequence of characters. Substrings with different start or end
positions are counted separately, even if they have the same characters.

Constraints:
1 <= s.length <= 1000
s contains lowercase English letters.

Example 1:

Input:
s = "abc"

Output:
3
("a", "b", "c")

Example 2:

Input:
s = "aaa"

Output:
6
("a", "a", "a", "aa", "aa", "aaa")
*/

/*
APPROACH:-

-> Every palindrome has a center: one character (odd length) or the gap between two characters (even length).
-> There are 2 * N - 1 centers in a string of length N. For each center, expand outwards while the characters on both sides are equal.
-> Every successful expansion step finds one more palindromic substring, so we add 1 to the count each time.
-> Expand for the odd center (left = right = i) and for the even center (left = i, right = i + 1).
-> Stop expanding when we cross the string border or when the two characters are different, because a bigger substring around a non-palindrome cannot be a palindrome.
-> Let N be the length of the string. Each center can expand up to N / 2 steps, so the time is N * N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int expandAndCount(string &s, int left, int right)
{
    int count = 0;

    while (left >= 0 && right < (int)s.size() && s[left] == s[right])
    {
        count++;
        left--;
        right++;
    }

    return count;
}

int countSubstrings(string s)
{
    int total = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        total = total + expandAndCount(s, i, i);
        total = total + expandAndCount(s, i, i + 1);
    }

    return total;
}

int main()
{
    string s = "aaa";

    int answer = countSubstrings(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(1)
*/
