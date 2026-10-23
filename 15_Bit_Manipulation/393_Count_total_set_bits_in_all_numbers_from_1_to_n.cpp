/*
QUESTION:-

Given a positive integer n, count the total number of set bits in the binary forms
of all the numbers from 1 to n.

Constraints:
1 <= n <= 100000

Example 1:

Input:
n = 3

Output:
4
(1 = 1, 2 = 10, 3 = 11: 1 + 1 + 2 = 4 set bits)

Example 2:

Input:
n = 6

Output:
9
(1, 1, 2, 1, 2, 2 set bits for 1 to 6)
*/

/*
APPROACH:-

-> Let bits[i] be the number of set bits in i. bits[0] = 0.
-> The number i is the number i / 2 (i shifted right by one bit) with one more bit added at the end. That last bit is 1 if i is odd and 0 if i is even. So bits[i] = bits[i >> 1] + (i & 1).
-> Example: 6 is 110. 6 shifted right is 3, which is 11 with 2 set bits. The last bit of 6 is 0, so 6 has 2 set bits.
-> Fill the table from 1 to n and add every value to a running total. The answer is the total.
-> We use the value of a smaller number that is already in the table, so every value is found in constant time.
-> Let n be the given number. We fill n values, so the time is n.
-> The table has n + 1 values, so the space is n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countTotalSetBits(int n)
{
    vector<int> bits(n + 1, 0);
    int total = 0;

    for (int i = 1; i <= n; i++)
    {
        bits[i] = bits[i >> 1] + (i & 1);
        total = total + bits[i];
    }

    return total;
}

int main()
{
    int n = 3;

    cout << countTotalSetBits(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(n)
*/
