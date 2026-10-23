/*
QUESTION:-

You are given coins of different denominations and a total amount. Every coin
can be used any number of times. Return the number of different combinations of
coins that make exactly that amount. Two combinations are the same if they use
the same number of coins of every denomination (the order of the coins does not
matter). If the amount cannot be made, return 0.

Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000 (all values are different)
0 <= amount <= 5000
The answer fits in a 64-bit signed integer.

Example 1:

Input:
coins = [1,2,5]
amount = 5

Output:
4
(5, 2+2+1, 2+1+1+1, 1+1+1+1+1)

Example 2:

Input:
coins = [2]
amount = 3

Output:
0
*/

/*
APPROACH:-

-> Let ways[a] be the number of combinations that make the amount a. There is exactly one way to make 0: use no coins, so ways[0] = 1.
-> To count combinations (not orders), process the coins one at a time in the outer loop.
-> For the current coin c, go through the amounts from c up to the total. Every combination for amount a - c can get one more coin c, so add ways[a - c] to ways[a].
-> Because a coin is fully processed before the next coin starts, a combination is always built in the coin order, so 1+2 and 2+1 are not counted twice.
-> The same coin can repeat because ways[a - c] already includes combinations that used coin c.
-> The answer is ways[amount].
-> Let N be the number of coins and A the amount. Every coin goes through A amounts, so the time is N * A.
-> The ways array has A + 1 cells, so the space is A.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countWaysToMakeAmount(vector<int> &coins, int amount)
{
    vector<long long> ways(amount + 1, 0);
    ways[0] = 1;

    for (int coin : coins)
    {
        for (int current = coin; current <= amount; current++)
        {
            ways[current] += ways[current - coin];
        }
    }

    return ways[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    long long answer = countWaysToMakeAmount(coins, amount);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * A)
SPACE COMPLEXITY = O(A)
*/
