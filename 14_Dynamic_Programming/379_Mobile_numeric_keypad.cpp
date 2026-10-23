/*
QUESTION:-

A mobile phone has this numeric keypad:

1 2 3
4 5 6
7 8 9
* 0 #

Count the number of different numbers of length n that can be typed, if you may
start from any of the digits 0 to 9, and each next digit must be the same key as
the current one, or the key just above, below, to the left or to the right of
it. The keys * and # cannot be pressed.

Constraints:
1 <= n <= 25
The answer fits in a 64-bit signed integer.

Example 1:

Input:
n = 2

Output:
36
(for example, from 5 you can type 55, 52, 54, 56 and 58)

Example 2:

Input:
n = 3

Output:
138
*/

/*
APPROACH:-

-> Write down the allowed next digits for every digit. For example, 0 can go to 0 and 8; 5 can go to 5, 2, 4, 6 and 8; 1 can go to 1, 2 and 4.
-> Let ways[d] be the number of valid numbers of the current length that start with the digit d. For length 1, every digit gives 1 number, so ways[d] = 1.
-> To go to the next length, a number that starts with d continues with a number of the shorter length that starts with an allowed next digit e. So the new ways[d] is the sum of ways[e] over all allowed next digits e of d.
-> Repeat this step until the length is n. The answer is the sum of ways[d] over all digits.
-> Let n be the length of the number. Each step looks at a fixed number of digits and keys (10 digits, at most 5 next digits each), so the time is n.
-> We keep only two arrays of 10 numbers, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countNumbers(int n)
{
    vector<vector<int>> nextDigits = {
        {0, 8},
        {1, 2, 4},
        {2, 1, 3, 5},
        {3, 2, 6},
        {4, 1, 5, 7},
        {5, 2, 4, 6, 8},
        {6, 3, 5, 9},
        {7, 4, 8},
        {8, 5, 7, 9, 0},
        {9, 6, 8}};

    vector<long long> ways(10, 1);

    for (int length = 2; length <= n; length++)
    {
        vector<long long> newWays(10, 0);

        for (int digit = 0; digit < 10; digit++)
        {
            for (int k = 0; k < (int)nextDigits[digit].size(); k++)
            {
                newWays[digit] = newWays[digit] + ways[nextDigits[digit][k]];
            }
        }

        ways = newWays;
    }

    long long total = 0;

    for (int digit = 0; digit < 10; digit++)
    {
        total = total + ways[digit];
    }

    return total;
}

int main()
{
    int n = 2;

    cout << countNumbers(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(1)
*/
