/*
QUESTION:-

Given two integers dividend and divisor, divide them without using the
multiplication, division and mod operators. Return the quotient, truncated
towards zero (so 7 / -2 gives -3). If the result is larger than the biggest
32-bit signed integer, return that biggest value.

Constraints:
-2147483648 <= dividend, divisor <= 2147483647
divisor != 0

Example 1:

Input:
dividend = 10, divisor = 3

Output:
3

Example 2:

Input:
dividend = 7, divisor = -2

Output:
-3
*/

/*
APPROACH:-

-> Work with positive numbers, and remember whether the answer is negative (it is negative when exactly one of the two numbers is negative). Use long long, so that the smallest 32-bit number can also be made positive.
-> Dividing means finding how many times the divisor fits into the dividend. Instead of subtracting the divisor one time after another, subtract bigger pieces: the divisor shifted left by 31, 30, ..., 0 places, which is the divisor multiplied by a power of two.
-> Go from the biggest shift to the smallest. If (divisor << shift) fits into what is left of the dividend, subtract it and add (1 << shift) to the quotient.
-> This works like long division in binary: the shifts we use are exactly the set bits of the quotient.
-> Example: 10 / 3. Shift 1: 3 << 1 = 6 fits, so the left part is 4 and the quotient gets 2. Shift 0: 3 fits into 4, so the left part is 1 and the quotient gets 1. The quotient is 3.
-> At the end apply the sign. The only case where the result does not fit in 32 bits is -2147483648 / -1, so in that case return the biggest 32-bit value.
-> The loop has 32 steps, so the time is constant. Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    long long a = dividend;
    long long b = divisor;

    bool negative = (a < 0) != (b < 0);

    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }

    long long quotient = 0;

    for (int shift = 31; shift >= 0; shift--)
    {
        if ((b << shift) <= a)
        {
            a = a - (b << shift);
            quotient = quotient + (1LL << shift);
        }
    }

    if (negative)
    {
        quotient = -quotient;
    }

    if (quotient > INT_MAX)
    {
        return INT_MAX;
    }

    return (int)quotient;
}

int main()
{
    int dividend = 10;
    int divisor = 3;

    cout << divide(dividend, divisor) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
