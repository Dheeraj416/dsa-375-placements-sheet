/*
QUESTION:-

Given a string of lowercase letters, rearrange its characters so that no two
adjacent characters are the same. If it is not possible, return "-1". If there
are several answers, return the one produced by the method in the approach below.

Constraints:
1 <= length of the string <= 100000

Example 1:

Input:
s = "aaabc"

Output:
acaba

Example 2:

Input:
s = "aaab"

Output:
-1
(three a's cannot be separated by only one other character)
*/

/*
APPROACH:-

-> A rearrangement is only possible if no letter appears more than (length + 1) / 2 times. Otherwise there are not enough other letters to separate it.
-> Greedy idea: always place the letter with the highest remaining count, but never the same letter as the one placed just before.
-> Put all the (count, letter) pairs in a max heap. Keep the previously placed letter in prev, with its remaining count, outside of the heap.
-> Repeat: take the top of the heap, append its letter to the result and reduce its count by 1. Then put the previous letter back into the heap if its count is still above 0. Now the letter just used becomes the new prev.
-> At the end, if the result has the same length as the input, return it. Otherwise the heap became empty too early, which means the rearrangement is impossible, so return "-1".
-> Let N be the length of the string. The heap has at most 26 letters, so every step costs log 26, which is constant. The time is N.
-> The heap and the counts are of constant size, but the result takes N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string rearrangeString(string s)
{
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < (int)s.size(); i++)
    {
        count[s[i] - 'a']++;
    }

    priority_queue<pair<int, char>> heap;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            heap.push({count[i], (char)('a' + i)});
        }
    }

    string result = "";
    pair<int, char> prev = {0, '#'};

    while (!heap.empty())
    {
        pair<int, char> current = heap.top();
        heap.pop();

        result += current.second;
        current.first--;

        if (prev.first > 0)
        {
            heap.push(prev);
        }

        prev = current;
    }

    if (result.size() != s.size())
    {
        return "-1";
    }

    return result;
}

int main()
{
    string s = "aaabc";

    cout << rearrangeString(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
