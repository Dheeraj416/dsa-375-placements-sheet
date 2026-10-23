/*
QUESTION:-

Characters of a string arrive one by one as a stream. After each character
arrives, find the first non repeating character among the characters read so
far. If there is none, print '#' for that position. Return the answers for all
positions as a string.

Constraints:
1 <= length of the stream <= 100000
The stream contains only lowercase letters.

Example 1:

Input:
stream = "aabc"

Output:
a#bb

Example 2:

Input:
stream = "zzxyz"

Output:
z#xxx
*/

/*
APPROACH:-

-> Keep a count array of size 26 with the number of times every letter has appeared, and a queue of letters that may still be non repeating.
-> When a new character arrives, increase its count and push it into the queue.
-> Remove from the front of the queue while the front character has a count greater than 1, because that character is repeating now and can never be the answer again.
-> After this cleaning, if the queue is empty there is no non repeating character, so add '#' to the result. Otherwise the front of the queue is the first non repeating character, so add it to the result.
-> Each character enters the queue once and leaves it at most once, so the cleaning costs N in total.
-> Let N be the length of the stream. The time is N.
-> The queue can hold up to N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string stream)
{
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }

    queue<char> pending;
    string result = "";

    for (int i = 0; i < (int)stream.size(); i++)
    {
        char c = stream[i];
        count[c - 'a']++;
        pending.push(c);

        while (!pending.empty() && count[pending.front() - 'a'] > 1)
        {
            pending.pop();
        }

        if (pending.empty())
        {
            result += '#';
        }
        else
        {
            result += pending.front();
        }
    }

    return result;
}

int main()
{
    string stream = "aabc";

    cout << firstNonRepeating(stream) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
