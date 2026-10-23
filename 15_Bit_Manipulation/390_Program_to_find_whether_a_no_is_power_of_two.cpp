/*
QUESTION:-

Given a non-negative integer n, return true if n is a power of two (1, 2, 4, 8,
16, ...), otherwise return false.

Constraints:
0 <= n <= 2147483647

Example 1:

Input:
n = 16

Output:
true

Example 2:

Input:
n = 18

Output:
false
*/

/*
APPROACH:-

-> A power of two has exactly one set bit in its binary form. For example 16 is 10000 and 8 is 1000.
-> The trick: n & (n - 1) removes the lowest set bit of n. If n has only one set bit, removing it leaves 0. If n has more than one set bit, something stays.
-> So n is a power of two exactly when n is greater than 0 and n & (n - 1) is 0.
-> The check n > 0 is needed because 0 has no set bit and is not a power of two, but 0 & (0 - 1) is also 0.
-> Example: 18 is 10010 and 17 is 10001, and their AND is 10000, which is not 0, so 18 is not a power of two.
-> We do a constant number of operations, so the time and the space are constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    int n = 16;

    cout << (isPowerOfTwo(n) ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
