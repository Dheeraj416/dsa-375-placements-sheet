/*
QUESTION:-

Given a number n, find the position of its only set bit. The positions are counted
from the right, starting with 1 for the lowest bit. If n has no set bit, or has
more than one set bit, return -1.

Constraints:
0 <= n <= 2147483647

Example 1:

Input:
n = 2

Output:
2
(2 is 10 in binary, and the only set bit is the second bit from the right)

Example 2:

Input:
n = 5

Output:
-1
(5 is 101 in binary, which has two set bits)
*/

/*
APPROACH:-

-> First check that n has exactly one set bit. This is true exactly when n is greater than 0 and n & (n - 1) is 0 (the same check as for a power of two). If not, return -1.
-> Now n is a power of two. Start with position 1 and shift n to the right one bit at a time while n is bigger than 1. Each shift moves the set bit one place to the right, so we add 1 to the position.
-> When n becomes 1, the set bit has reached the lowest place, and the counter holds the original position of the bit.
-> Example: 8 is 1000. Shifts: 8 -> 4 -> 2 -> 1, which is 3 shifts, so the position is 1 + 3 = 4.
-> A number has at most 31 bits, so the loop runs at most 31 times and the time is constant.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int positionOfSetBit(int n)
{
    if (n <= 0 || (n & (n - 1)) != 0)
    {
        return -1;
    }

    int position = 1;

    while (n > 1)
    {
        n = n >> 1;
        position++;
    }

    return position;
}

int main()
{
    int n = 2;

    cout << positionOfSetBit(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
