/*
QUESTION:-

Given two numbers A and B, count the number of bits that must be flipped to
convert A to B.

Constraints:
0 <= A, B <= 2147483647

Example 1:

Input:
A = 10, B = 20

Output:
4
(10 is 01010 and 20 is 10100: four bits are different)

Example 2:

Input:
A = 20, B = 25

Output:
3
(20 is 10100 and 25 is 11001: three bits are different)
*/

/*
APPROACH:-

-> The bits that must be flipped are exactly the bits where A and B are different.
-> The XOR of two numbers has a 1 at every position where the bits are different. So A ^ B marks the bits we have to flip.
-> Count the set bits of A ^ B. To count them, repeat x = x & (x - 1), which removes the lowest set bit, and count how many times it can be done before x becomes 0.
-> Example: 10 ^ 20 = 01010 ^ 10100 = 11110, which has 4 set bits.
-> A number has at most 31 bits, so the loop runs at most 31 times and the time is constant.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countBitsToFlip(int a, int b)
{
    int x = a ^ b;
    int count = 0;

    while (x != 0)
    {
        x = x & (x - 1);
        count++;
    }

    return count;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << countBitsToFlip(a, b) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
