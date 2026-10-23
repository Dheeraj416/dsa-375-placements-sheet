/*
QUESTION:-

You are given a string s of uppercase English letters and an integer k. In one
operation you can change any character of the string to any other uppercase
letter. You can do at most k operations. Return the length of the longest
substring that contains only one repeating letter after the operations.

Constraints:
1 <= s.length <= 100000
s contains only uppercase English letters.
0 <= k <= s.length

Example 1:

Input:
s = "ABAB"
k = 2

Output:
4
(replace the two A's with B, or the two B's with A)

Example 2:

Input:
s = "AABABBA"
k = 1

Output:
4
(replace the middle 'B' of "AABA" to get "AAAA")
*/

/*
APPROACH:-

-> Use a sliding window [left, right]. A window can be turned into one repeating letter with (window length - count of the most frequent letter in it) operations, because we change everything except the most frequent letter.
-> Keep a count array of the 26 letters inside the window, and a variable maxFrequency with the highest count seen in any window so far.
-> Move right forward, add its letter to the counts and update maxFrequency.
-> If the window length minus maxFrequency is more than k, the window needs too many changes, so shrink it by removing the letter at left and moving left forward.
-> maxFrequency is never lowered when we shrink. That is fine, because only a window with a higher frequency than before can give a longer answer.
-> The answer is the largest window length seen.
-> Let N be the length of the string. Both pointers only move forward, so the time is N.
-> The count array has 26 cells, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> count(26, 0);
    int left = 0;
    int maxFrequency = 0;
    int best = 0;

    for (int right = 0; right < (int)s.size(); right++)
    {
        count[s[right] - 'A']++;
        maxFrequency = max(maxFrequency, count[s[right] - 'A']);

        while ((right - left + 1) - maxFrequency > k)
        {
            count[s[left] - 'A']--;
            left++;
        }

        best = max(best, right - left + 1);
    }

    return best;
}

int main()
{
    string s = "ABAB";
    int k = 2;

    int answer = characterReplacement(s, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
