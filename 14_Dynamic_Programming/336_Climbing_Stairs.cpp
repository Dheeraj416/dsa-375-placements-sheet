/*
QUESTION:-

You are climbing a staircase that has n steps. In one move you can climb either 1
step or 2 steps. In how many distinct ways can you climb to the top?

Constraints:
1 <= n <= 45

Example 1:

Input:
n = 3

Output:
3
(1+1+1, 1+2, 2+1)

Example 2:

Input:
n = 5

Output:
8
*/

/*
APPROACH:-

-> To stand on step i, the last move was either from step i - 1 (a 1-step move) or from step i - 2 (a 2-step move). So ways(i) = ways(i - 1) + ways(i - 2).
-> The base cases: there is 1 way to reach step 1, and 2 ways to reach step 2 (1+1 and 2).
-> This is the Fibonacci sequence. Since ways(i) needs only the two previous values, we keep two variables instead of a whole table.
-> Start from step 3 and move up to step n, each time computing the new value and shifting the two variables.
-> Let n be the number of steps. We make one pass, so the time is n.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    int oneBefore = 2;
    int twoBefore = 1;

    for (int step = 3; step <= n; step++)
    {
        int current = oneBefore + twoBefore;
        twoBefore = oneBefore;
        oneBefore = current;
    }

    return oneBefore;
}

int main()
{
    int n = 3;

    cout << climbStairs(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(1)
*/
