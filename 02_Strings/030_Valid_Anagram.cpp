/*
QUESTION:-

Given two strings s and t, return true if t is an anagram of s, and false
otherwise. An anagram is a word formed by rearranging the letters of another
word, using all the original letters exactly once.

Constraints:
1 <= s.length, t.length <= 50000
s and t consist of lowercase English letters.

Example 1:

Input:
s = "anagram", t = "nagaram"

Output:
true

Example 2:

Input:
s = "rat", t = "car"

Output:
false
*/

/*
APPROACH:-

-> If the two strings have different lengths they cannot be anagrams, so return false at once.
-> Use an array of 26 counters, one for each lowercase letter.
-> For every character of s increase its counter, and for the character at the same position of t decrease its counter.
-> If the two strings contain the same letters with the same frequencies, every counter ends at 0.
-> If any counter is not zero, the letter counts differ, so the strings are not anagrams.
-> The counter array has a fixed size of 26, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string &first, string &second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    vector<int> counts(26, 0);

    for (int i = 0; i < first.size(); i++)
    {
        counts[first[i] - 'a']++;
        counts[second[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string first = "anagram";
    string second = "nagaram";

    bool answer = isAnagram(first, second);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
