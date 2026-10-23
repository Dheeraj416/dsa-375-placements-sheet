/*
QUESTION:-

Given a number n, count the natural numbers from 1 to n whose every permutation
of digits is greater than or equal to the number itself. For example 123 is
such a number, because all the permutations (132, 213, 231, 312, 321) are
greater, but 21 is not, because 12 is smaller than 21.

Constraints:
1 <= n <= 1000000000

Example 1:

Input:
n = 15

Output:
14
(the numbers are 1 to 9 and 11, 12, 13, 14, 15; 10 is not counted because 01 < 10)

Example 2:

Input:
n = 100

Output:
54
(9 one digit numbers and 45 two digit numbers; 100 is not counted)
*/

/*
APPROACH:-

-> A number has this property exactly when its digits are in non-decreasing order from left to right. If some digit is bigger than the digit after it, swapping them gives a smaller number.
-> So we only need to count the numbers up to n with non-decreasing digits. There are very few of them, so we generate them with a queue instead of checking every number.
-> Put the digits 1 to 9 in the queue. Take a number x from the front. If x is greater than n, skip it, because all the numbers generated from it are even larger.
-> Otherwise count x, and push the numbers x * 10 + d for every digit d from the last digit of x up to 9. These are the next longer numbers with non-decreasing digits.
-> Use long long, because x * 10 can go beyond the int range.
-> Let C be the count of numbers with non-decreasing digits up to n (at most about 50000 for n up to 10^9). Each is generated and handled once, so the time is C.
-> The queue holds at most C numbers, so the space is C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countNumbers(int n)
{
    queue<long long> pending;

    for (int digit = 1; digit <= 9; digit++)
    {
        pending.push(digit);
    }

    int count = 0;

    while (!pending.empty())
    {
        long long x = pending.front();
        pending.pop();

        if (x > n)
        {
            continue;
        }

        count++;

        int lastDigit = x % 10;
        for (int digit = lastDigit; digit <= 9; digit++)
        {
            pending.push(x * 10 + digit);
        }
    }

    return count;
}

int main()
{
    int n = 15;

    cout << countNumbers(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(C)
SPACE COMPLEXITY = O(C)
*/
