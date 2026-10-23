/*
QUESTION:-

You have two empty jugs with capacities m and n liters, and an unlimited water
supply. Using only these operations: fill a jug completely, empty a jug
completely, and pour water from one jug into the other until the first is empty
or the second is full, measure exactly d liters in one of the jugs. Find the
minimum number of steps, by following one fixed pouring strategy (always pour
from the same jug into the other jug) and trying both choices of the jug. If it
is not possible, return -1.

Constraints:
1 <= m, n <= 1000000
1 <= d <= 1000000

Example 1:

Input:
m = 3, n = 5, d = 4

Output:
6

Example 2:

Input:
m = 4, n = 3, d = 2

Output:
4
*/

/*
APPROACH:-

-> The amount d can be measured only if d is not more than the larger jug, and d is a multiple of gcd(m, n) (the greatest common divisor of the two capacities). Otherwise the answer is -1.
-> If it can be measured, simulate this strategy: take a source jug and a target jug. Fill the source jug (1 step). Then repeat: pour from the source into the target (1 step) until one of the jugs has d liters. If the source gets empty, fill it again (1 step). If the target gets full, empty it (1 step).
-> Run the simulation twice: once with the jug of capacity m as the source, and once with the jug of capacity n as the source. The answer is the smaller number of steps.
-> In each simulation the amounts follow a repeating pattern, so d is reached after at most about m + n steps.
-> Let M and N be the capacities. The simulations take at most about M + N steps, and the gcd takes log, so the time is M + N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int pourSteps(int fromCapacity, int toCapacity, int d)
{
    int from = fromCapacity;
    int to = 0;
    int steps = 1;

    while (from != d && to != d)
    {
        int amount = min(from, toCapacity - to);

        to += amount;
        from -= amount;
        steps++;

        if (from == d || to == d)
        {
            break;
        }

        if (from == 0)
        {
            from = fromCapacity;
            steps++;
        }

        if (to == toCapacity)
        {
            to = 0;
            steps++;
        }
    }

    return steps;
}

int minimumSteps(int m, int n, int d)
{
    if (d > max(m, n) || d % gcd(m, n) != 0)
    {
        return -1;
    }

    return min(pourSteps(m, n, d), pourSteps(n, m, d));
}

int main()
{
    int m = 3;
    int n = 5;
    int d = 4;

    cout << minimumSteps(m, n, d) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(M + N)
SPACE COMPLEXITY = O(1)
*/
