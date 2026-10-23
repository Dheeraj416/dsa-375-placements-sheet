/*
QUESTION:-

Given the number of digits d and the sum of digits s, find the smallest number
(without leading zeros) that has exactly d digits and whose digits add up to s.
If there is no such number, return -1. The answer can be very large, so return it
as a string.

Constraints:
1 <= d <= 100
1 <= s <= 900

Example 1:

Input:
s = 9, d = 2

Output:
18
(the numbers 18, 27, 36, 45, ... have the digit sum 9, and 18 is the smallest)

Example 2:

Input:
s = 20, d = 3

Output:
299
(a three digit number with digit sum 20; 299 is the smallest)
*/

/*
APPROACH:-

-> If s is more than 9 * d, even the largest digits cannot reach the sum, so the answer is -1.
-> To make the number small, the leftmost digits should be small and the rightmost digits should be large. So fill the digits from the right: give every position the largest digit possible, which is min(9, what is left of the sum).
-> The first digit cannot be 0, so keep 1 aside for it in the beginning: subtract 1 from s first.
-> Fill the positions d - 1 down to 1 with min(9, s) and reduce s each time. Whatever is left in s, plus the 1 we kept aside, is the first digit.
-> Because we subtracted 1 and s <= 9 * d, the first digit is never more than 9.
-> Let D be the number of digits. We fill each digit once, so the time is D.
-> The answer string has D characters, so the space is D.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d)
{
    if (s > 9 * d)
    {
        return "-1";
    }

    string result(d, '0');
    s = s - 1;

    for (int i = d - 1; i >= 1; i--)
    {
        int digit = min(9, s);
        result[i] = (char)('0' + digit);
        s = s - digit;
    }

    result[0] = (char)('0' + s + 1);

    return result;
}

int main()
{
    int s = 9;
    int d = 2;

    cout << smallestNumber(s, d) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(D)
SPACE COMPLEXITY = O(D)
*/
