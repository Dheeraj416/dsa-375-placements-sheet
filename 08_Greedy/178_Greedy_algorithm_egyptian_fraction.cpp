/*
QUESTION:-

Every positive fraction can be written as a sum of distinct unit fractions
(fractions with numerator 1). Such a sum is called an Egyptian fraction. Given a
fraction nr/dr (nr < dr), write it as a sum of unit fractions using the greedy
method: always take the largest unit fraction that does not exceed what is left.
Print the unit fractions in the form 1/x separated by " + ".

Constraints:
1 <= nr < dr <= 10000

Example 1:

Input:
nr = 6, dr = 14

Output:
1/3 + 1/11 + 1/231

Example 2:

Input:
nr = 12, dr = 13

Output:
1/2 + 1/3 + 1/12 + 1/156
*/

/*
APPROACH:-

-> The largest unit fraction 1/x that is not more than nr/dr has x = ceil(dr / nr). In integers, x = (dr + nr - 1) / nr.
-> Print 1/x. Then subtract it from the fraction: nr/dr - 1/x = (nr * x - dr) / (dr * x). So the new numerator is nr * x - dr and the new denominator is dr * x.
-> Repeat with the new fraction until the numerator becomes 0. The greedy method always ends, because the numerator becomes strictly smaller each time.
-> Use long long because the denominators grow very fast.
-> Let K be the number of unit fractions produced. Every step takes constant time, so the time is K.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void printEgyptian(long long nr, long long dr)
{
    bool first = true;

    while (nr != 0)
    {
        long long x = (dr + nr - 1) / nr;

        if (!first)
        {
            cout << " + ";
        }
        cout << "1/" << x;
        first = false;

        nr = nr * x - dr;
        dr = dr * x;
    }

    cout << "\n";
}

int main()
{
    long long nr = 6;
    long long dr = 14;

    printEgyptian(nr, dr);

    return 0;
}

/*
TIME COMPLEXITY = O(K)
SPACE COMPLEXITY = O(1)
*/
