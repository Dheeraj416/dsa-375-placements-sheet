/*
QUESTION:-

There are n coins in a row with values coins[0..n-1]. Two players take turns. In
each turn, a player takes either the first or the last coin of the row. Player 1
moves first and both players play in the best possible way. Return the maximum
total value of coins that player 1 can collect.

Constraints:
1 <= n <= 1000
1 <= coins[i] <= 1000

Example 1:

Input:
coins = [8,15,3,7]

Output:
22
(player 1 takes 7, player 2 takes 8, player 1 takes 15, player 2 takes 3)

Example 2:

Input:
coins = [20,30,2,2,2,10]

Output:
42
*/

/*
APPROACH:-

-> Instead of tracking both scores, track the difference. Let diff[i][j] be the best value of (my coins minus the opponent's coins) that the player to move can get from the coins i to j.
-> If only one coin is left, the player takes it, so diff[i][i] = coins[i].
-> Otherwise the player takes the first coin or the last coin. If he takes the first coin, he gets coins[i], and then the opponent plays on coins i + 1 to j and gets the difference diff[i + 1][j] in his favour. So this choice gives coins[i] - diff[i + 1][j].
-> In the same way, taking the last coin gives coins[j] - diff[i][j - 1]. The player picks the larger of the two.
-> Fill the table by the length of the range, from 2 up to n. At the end, diff[0][n - 1] = (player 1 total) - (player 2 total).
-> The two totals add up to the sum of all coins. So player 1 gets (sum + diff[0][n - 1]) / 2.
-> Let N be the number of coins. The table has N * N cells, each filled in constant time, so the time and the space are both N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int optimalStrategy(vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> diff(n, vector<int>(n, 0));
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        diff[i][i] = coins[i];
        total = total + coins[i];
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i + length - 1 < n; i++)
        {
            int j = i + length - 1;

            diff[i][j] = max(coins[i] - diff[i + 1][j], coins[j] - diff[i][j - 1]);
        }
    }

    return (total + diff[0][n - 1]) / 2;
}

int main()
{
    vector<int> coins = {8, 15, 3, 7};

    cout << optimalStrategy(coins) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
