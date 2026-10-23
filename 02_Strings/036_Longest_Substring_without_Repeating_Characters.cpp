/*
QUESTION:-

Given a string s, find the length of the longest substring that does not
contain any repeating character.

Constraints:
0 <= s.length <= 50000
s consists of English letters, digits, symbols and spaces.

Example 1:

Input:
s = "abcabcbb"

Output:
3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input:
s = "bbbbb"

Output:
1
*/

/*
APPROACH:-

-> Use the sliding window technique with two pointers, left and right.
-> Keep an array lastSeen that stores the most recent index of every character.
-> Move right one step at a time. If the character at right was seen inside the current window, move left to just after its last position.
-> Update lastSeen for the character and compute the window length right - left + 1.
-> Keep the maximum window length seen.
-> The left pointer only moves forward, so each character is processed a constant number of times.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string &text)
{
    vector<int> lastSeen(256, -1);
    int left = 0;
    int longest = 0;

    for (int right = 0; right < (int)text.size(); right++)
    {
        int character = (unsigned char)text[right];

        if (lastSeen[character] >= left)
        {
            left = lastSeen[character] + 1;
        }

        lastSeen[character] = right;
        longest = max(longest, right - left + 1);
    }

    return longest;
}

int main()
{
    string text = "abcabcbb";

    int answer = lengthOfLongestSubstring(text);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
