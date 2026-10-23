/*
QUESTION:-

Given two numbers X and Y, and a range [L, R], copy the set bits of Y that are
in the range L to R into X. The positions are counted from the right, starting
with 1 for the lowest bit. Bits of X outside the range, and bits of X that are
already set, are not changed. Return the new X.

Constraints:
0 <= X, Y <= 2147483647
1 <= L <= R <= 31

Example 1:

Input:
X = 10, Y = 13, L = 2, R = 3

Output:
14
(Y = 1101 has a set bit at position 3 in the range. X = 1010 becomes 1110)

Example 2:

Input:
X = 8, Y = 7, L = 1, R = 3

Output:
15
(Y = 0111 has set bits at positions 1, 2 and 3. X = 1000 becomes 1111)
*/

/*
APPROACH:-

-> Go through the positions from L to R. The bit at position p is found by shifting right by p - 1 places and taking the last bit: (Y >> (p - 1)) & 1.
-> If that bit of Y is 1, set the same position in X with OR: X = X | (1 << (p - 1)). OR never clears a bit, so the bits of X that were already set stay set.
-> If the bit of Y is 0, do nothing. We copy only the set bits, so X keeps its own bit at this position.
-> Positions outside the range L to R are never looked at, so they are not changed.
-> Example: X = 1010, Y = 1101, range 2 to 3. Position 2 of Y is 0, so skip it. Position 3 of Y is 1, so X = 1010 | 0100 = 1110, which is 14.
-> The range has at most 31 positions, so the time is constant.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int copySetBits(int x, int y, int left, int right)
{
    for (int position = left; position <= right; position++)
    {
        if ((y >> (position - 1)) & 1)
        {
            x = x | (1 << (position - 1));
        }
    }

    return x;
}

int main()
{
    int x = 10;
    int y = 13;
    int l = 2;
    int r = 3;

    cout << copySetBits(x, y, l, r) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
