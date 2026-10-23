/*
QUESTION:-

Given a string, print all the characters that appear more than once together
with the number of times they appear. Print the characters in increasing
character order, one per line. If there are no duplicates, print -1.

Constraints:
1 <= s.length <= 100000
s contains printable ASCII characters.

Example 1:

Input:
s = "test string"

Output:
s 2
t 3

Example 2:

Input:
s = "geeksforgeeks"

Output:
e 4
g 2
k 2
s 2
*/

/*
APPROACH:-

-> Count how many times every character appears using a map from character to count. A std::map keeps its keys sorted, so reading it from start to end gives increasing character order.
-> Go through the string once and increase the count of each character.
-> Then go through the map. Every character whose count is bigger than 1 is a duplicate, so print it with its count.
-> Keep a flag to know whether anything was printed. If there is no duplicate, print -1.
-> Let N be the length of the string and K the number of different characters (at most 128). Counting costs N and printing costs K, so the time is N.
-> The map stores at most K characters, which is a constant, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void printDuplicates(string s)
{
    map<char, int> count;

    for (char c : s)
    {
        count[c]++;
    }

    bool found = false;

    for (pair<char, int> entry : count)
    {
        if (entry.second > 1)
        {
            cout << entry.first << " " << entry.second << "\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << -1 << "\n";
    }
}

int main()
{
    string s = "test string";

    printDuplicates(s);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
