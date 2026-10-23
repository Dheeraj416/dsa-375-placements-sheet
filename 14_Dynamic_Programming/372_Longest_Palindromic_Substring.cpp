/*
QUESTION:-

Given a string s, return the longest palindromic substring in s. A palindrome
reads the same forwards and backwards. If there are several answers of the same
length, return the one that appears first.

Constraints:
1 <= s.length <= 1000
s consists of digits and English letters.

Example 1:

Input:
s = "babad"

Output:
"bab"
Explanation: "aba" is also a valid answer, but "bab" appears first.

Example 2:

Input:
s = "cbbd"

Output:
"bb"
*/

/*
APPROACH:-

-> Every palindrome has a center. For a string of length N there are 2N - 1 centers: N letters (odd length palindromes) and N - 1 gaps between two letters (even length palindromes).
-> For each center expand outwards while the characters on both sides are equal.
-> When the expansion stops, the palindrome length is right - left - 1.
-> If this length is strictly larger than the best length so far, remember its start and length.
-> Using a strictly larger comparison keeps the earliest palindrome when lengths are equal.
-> Finally return the substring of the best start and length.
-> This is simpler than dynamic programming and needs no extra table.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string &text)
{
    int n = (int)text.size();
    int bestStart = 0;
    int bestLength = 1;

    for (int center = 0; center < n; center++)
    {
        for (int type = 0; type < 2; type++)
        {
            int left = center;
            int right = center + type;

            while (left >= 0 && right < n && text[left] == text[right])
            {
                left--;
                right++;
            }

            int length = right - left - 1;

            if (length > bestLength)
            {
                bestLength = length;
                bestStart = left + 1;
            }
        }
    }

    return text.substr(bestStart, bestLength);
}

int main()
{
    string text = "babad";

    string answer = longestPalindrome(text);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY = O(1)
*/
