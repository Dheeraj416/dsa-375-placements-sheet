/*
QUESTION:-

Given a number as a string of digits and an integer k, return the largest
number that can be made by swapping the positions of two digits at most k
times (the two digits can be anywhere in the number).

Constraints:
1 <= number.length <= 18
0 <= k <= 10
The number has no leading zeros.

Example 1:

Input:
number = "129814999"
k = 4

Output:
999984211

Example 2:

Input:
number = "1234567"
k = 4

Output:
7654321
*/

/*
APPROACH:-

-> To make the number large, we want the largest digits at the front. Process the positions from left to right.
-> At position pos, find the largest digit among the positions pos to the end. If this largest digit is already at pos, no swap is needed, so move on without using a swap.
-> Otherwise we use one swap to bring the largest digit to pos. But the largest digit may appear several times, and we do not know which copy is best (it affects what remains for later positions). So we try each position j of the largest digit: swap, recurse for pos + 1 with k - 1, and swap back (backtracking).
-> After every swap, compare the new number with the best one found so far (as strings of equal length, so a normal string compare works) and keep the larger.
-> Stop when k becomes 0 or pos reaches the end.
-> Let N be the number of digits. In the worst case the number of tries grows like N^K, so the time is N^K * N.
-> The recursion goes at most K deep and we store the best string, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void findMax(string &number, int k, int pos, string &best)
{
    if (k == 0 || pos >= (int)number.size())
    {
        return;
    }

    char largest = number[pos];

    for (int i = pos + 1; i < (int)number.size(); i++)
    {
        if (number[i] > largest)
        {
            largest = number[i];
        }
    }

    if (largest != number[pos])
    {
        k--;
    }

    for (int j = (int)number.size() - 1; j >= pos; j--)
    {
        if (number[j] == largest)
        {
            swap(number[pos], number[j]);

            if (number > best)
            {
                best = number;
            }

            findMax(number, k, pos + 1, best);

            swap(number[pos], number[j]);
        }
    }
}

string maximumNumber(string number, int k)
{
    string best = number;

    findMax(number, k, 0, best);

    return best;
}

int main()
{
    string number = "129814999";
    int k = 4;

    string answer = maximumNumber(number, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N^K * N)
SPACE COMPLEXITY = O(N)
*/
