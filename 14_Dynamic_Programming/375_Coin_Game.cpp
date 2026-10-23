/*
QUESTION:-

Two players play a game with a pile of N coins. In every move, a player must take
from 1 to 5 coins from the pile. The player who takes the last coin loses the
game. The first player moves first, and both players play in the best possible
way. Find out which player wins: print "First" or "Second".

Constraints:
1 <= N <= 100000

Example 1:

Input:
N = 4

Output:
First
(the first player takes 3 coins and leaves 1 coin, so the second player must take the last coin)

Example 2:

Input:
N = 7

Output:
Second
(whatever the first player takes, the second player can leave exactly 1 coin)
*/

/*
APPROACH:-

-> Let wins[i] be true if the player who is to move wins when i coins are left.
-> With 1 coin left, the player must take it and loses, so wins[1] = false.
-> With i coins left, the player can take k coins, for k from 1 to 5. Taking all i coins (k = i) loses, so only k < i is useful, and it leaves i - k coins for the opponent.
-> If there is any move that leaves the opponent in a losing position (wins[i - k] is false), then the player wins: wins[i] = true. Otherwise every move leaves a winning position for the opponent, so wins[i] = false.
-> Fill i from 2 up to N. If wins[N] is true, the first player wins, otherwise the second player wins.
-> Let N be the number of coins. For each value of i we try at most 5 moves, so the time is N.
-> The wins array has N + 1 values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string coinGame(int n)
{
    vector<bool> wins(n + 1, false);

    for (int i = 2; i <= n; i++)
    {
        for (int take = 1; take <= 5 && take < i; take++)
        {
            if (wins[i - take] == false)
            {
                wins[i] = true;
            }
        }
    }

    if (wins[n])
    {
        return "First";
    }

    return "Second";
}

int main()
{
    int n = 4;

    cout << coinGame(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
