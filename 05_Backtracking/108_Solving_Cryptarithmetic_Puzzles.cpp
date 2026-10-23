/*
QUESTION:-

A cryptarithmetic puzzle is a sum of two words that equals a third word, for
example SEND + MORE = MONEY. Every letter stands for a different digit (0 to 9),
different letters get different digits, and the first letter of a word cannot be
zero. Given three words word1, word2 and result, find an assignment of digits
to letters so that word1 + word2 = result. Print the letters in alphabetical
order with their digits. If there is no solution, print "No solution".

Constraints:
1 <= length of each word <= 8
The words contain uppercase letters, and there are at most 10 different letters in total.

Example 1:

Input:
word1 = SEND
word2 = MORE
result = MONEY

Output:
D=7 E=5 M=1 N=6 O=0 R=8 S=9 Y=2
(9567 + 1085 = 10652)

Example 2:

Input:
word1 = TO
word2 = GO
result = OUT

Output:
G=8 O=1 T=2 U=0
(21 + 81 = 102)
*/

/*
APPROACH:-

-> Collect the different letters of the three words (at most 10), in alphabetical order. Each letter must get its own digit.
-> Use backtracking: assign a digit to the first letter, then to the second letter, and so on. Keep an array used[10] so that a digit is never given to two letters.
-> Skip a digit 0 for a letter that is the first letter of any word, because numbers cannot start with 0.
-> When all the letters have digits, convert the three words into numbers using the digits. If word1 + word2 equals result, we found the solution, so return true.
-> Otherwise undo the last assignment (backtrack) and try the next digit. If no digit works for a letter, return false so the previous letter tries another digit.
-> Let L be the number of different letters (at most 10). We try at most 10 * 9 * 8 ... assignments, which is 10! / (10 - L)!, and checking one costs the word lengths, so the time is 10! / (10 - L)! * N where N is the total length of the words.
-> The mapping and the used array take constant space, plus the recursion of L levels, so the space is L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long wordValue(string &word, int digitOf[26])
{
    long long value = 0;

    for (char c : word)
    {
        value = value * 10 + digitOf[c - 'A'];
    }

    return value;
}

bool assignDigits(int position, vector<char> &letters, int digitOf[26], bool used[10], bool cannotBeZero[26], vector<string> &words)
{
    if (position == (int)letters.size())
    {
        long long first = wordValue(words[0], digitOf);
        long long second = wordValue(words[1], digitOf);
        long long result = wordValue(words[2], digitOf);

        return first + second == result;
    }

    char letter = letters[position];

    for (int digit = 0; digit <= 9; digit++)
    {
        if (used[digit])
        {
            continue;
        }

        if (digit == 0 && cannotBeZero[letter - 'A'])
        {
            continue;
        }

        used[digit] = true;
        digitOf[letter - 'A'] = digit;

        if (assignDigits(position + 1, letters, digitOf, used, cannotBeZero, words))
        {
            return true;
        }

        used[digit] = false;
    }

    return false;
}

int main()
{
    vector<string> words = {"SEND", "MORE", "MONEY"};

    set<char> letterSet;
    bool cannotBeZero[26] = {false};

    for (string &word : words)
    {
        cannotBeZero[word[0] - 'A'] = true;

        for (char c : word)
        {
            letterSet.insert(c);
        }
    }

    vector<char> letters(letterSet.begin(), letterSet.end());
    int digitOf[26] = {0};
    bool used[10] = {false};

    if (letters.size() <= 10 && assignDigits(0, letters, digitOf, used, cannotBeZero, words))
    {
        for (int i = 0; i < (int)letters.size(); i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << letters[i] << "=" << digitOf[letters[i] - 'A'];
        }
        cout << "\n";
    }
    else
    {
        cout << "No solution\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(10! / (10 - L)! * N)
SPACE COMPLEXITY = O(L)
*/
