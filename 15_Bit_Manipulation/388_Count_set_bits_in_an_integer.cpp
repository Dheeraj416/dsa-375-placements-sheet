/*
QUESTION:-

Given a non-negative integer n, return the number of set bits in its binary
representation. A set bit is a bit that has the value 1.

Constraints:
0 <= n <= 2147483647

Example 1:

Input:
n = 11

Output:
3
(11 is 1011 in binary, which has three 1s)

Example 2:

Input:
n = 128

Output:
1
(128 is 10000000 in binary)
*/

/*
APPROACH:-

-> The trick: n & (n - 1) removes the lowest set bit of n. Subtracting 1 flips the lowest set bit to 0 and turns all the zeros after it into 1s, so the AND keeps everything above that bit and clears the rest.
-> Example: 1100 & 1011 = 1000, and the lowest set bit is gone.
-> So repeat: while n is not 0, do n = n & (n - 1) and add 1 to the count. The number of repetitions is exactly the number of set bits.
-> This is better than checking all 31 bits one by one, because we only loop once for every set bit.
-> Edge case: n = 0 has no set bits, the loop does not run and the answer is 0.
-> Let K be the number of set bits in n (K is at most 31). The loop runs K times, so the time is K.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main()
{
    int n = 11;

    int answer = countSetBits(n);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(K)
SPACE COMPLEXITY = O(1)
*/
