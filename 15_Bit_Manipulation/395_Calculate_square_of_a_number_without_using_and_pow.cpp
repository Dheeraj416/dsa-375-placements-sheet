/*
QUESTION:-

Given an integer n, return its square without using the multiplication operator
*, the division operator / and the pow() function.

Constraints:
-1000000000 <= n <= 1000000000

Example 1:

Input:
n = 5

Output:
25

Example 2:

Input:
n = -4

Output:
16
*/

/*
APPROACH:-

-> The square of a number is the number multiplied by itself. Multiplication can be done with shifts and additions: write the second number in binary, and for every set bit at position i, add the first number shifted left by i places.
-> Example: 5 * 5 where the second 5 is 101 in binary. The set bits are at positions 0 and 2, so the result is (5 << 0) + (5 << 2) = 5 + 20 = 25.
-> The square of a negative number is the same as the square of its positive value, so first change a negative n to -n.
-> Use a long long so that large results do not overflow.
-> A number has at most 31 bits, so the loop has 31 steps and the time is constant.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long square(int n)
{
    long long number = n;

    if (number < 0)
    {
        number = -number;
    }

    long long result = 0;

    for (int bit = 0; bit < 31; bit++)
    {
        if ((number >> bit) & 1)
        {
            result = result + (number << bit);
        }
    }

    return result;
}

int main()
{
    int n = 5;

    cout << square(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
