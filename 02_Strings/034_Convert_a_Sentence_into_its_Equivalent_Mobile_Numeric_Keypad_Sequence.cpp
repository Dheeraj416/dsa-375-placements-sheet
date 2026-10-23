/*
QUESTION:-

On an old mobile phone keypad, the letters are written by pressing keys several
times: A = 2, B = 22, C = 222, D = 3, E = 33, F = 333, G = 4, H = 44, I = 444,
J = 5, K = 55, L = 555, M = 6, N = 66, O = 666, P = 7, Q = 77, R = 777, S = 7777,
T = 8, U = 88, V = 888, W = 9, X = 99, Y = 999, Z = 9999, and a space is 0. Given
a sentence of uppercase letters and spaces, return the sequence of key presses
that writes the sentence.

Constraints:
1 <= s.length <= 100000
s contains uppercase English letters and spaces.

Example 1:

Input:
s = "GEEKSFORGEEKS"

Output:
4333355777733366677743333557777

Example 2:

Input:
s = "HELLO WORLD"

Output:
4433555555666096667775553
*/

/*
APPROACH:-

-> Store the key sequence of every letter in an array of 26 strings: index 0 holds "2" for A, index 1 holds "22" for B, and so on up to "9999" for Z.
-> Go through the sentence. For a space, append "0". For a letter, find its index with letter - 'A' and append the string stored at that index.
-> The answer is the concatenation of all these pieces in order.
-> Example: H = 44, E = 33, L = 555, L = 555, O = 666, space = 0, and so on, which gives 4433555555666096667775553.
-> Let N be the length of the sentence. Every character appends at most 4 digits, so the time is N.
-> The answer has up to 4 * N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string toKeypadSequence(string s)
{
    string keys[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6",
                       "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

    string result = "";

    for (char c : s)
    {
        if (c == ' ')
        {
            result = result + "0";
        }
        else
        {
            result = result + keys[c - 'A'];
        }
    }

    return result;
}

int main()
{
    string s = "GEEKSFORGEEKS";

    string answer = toKeypadSequence(s);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
