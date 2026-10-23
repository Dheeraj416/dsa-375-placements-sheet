/*
QUESTION:-

Two players A and B play a game with n coins. In every move, a player can take 1
coin, x coins or y coins from the pile. The player who takes the last coin wins.
A always moves first and both players play in the best possible way. Find out
who wins and print "A" or "B".

Constraints:
1 <= n, x, y <= 100000

Example 1:

Input:
n = 5, x = 3, y = 4

Output:
A
(A takes 3 coins and leaves 2 coins; B can only take 1 coin, and then A takes the last coin)

Example 2:

Input:
n = 2, x = 3, y = 4

Output:
B
(A can only take 1 coin, then B takes the last coin)
*/

/*
APPROACH:-

-> Let wins[i] be true if the player who is to move wins when i coins are left.
-> With 0 coins left, the player to move has no coin to take. The opponent took the last coin and has won, so wins[0] = false.
-> With i coins left, the player can take 1 coin (if i >= 1), x coins (if i >= x) or y coins (if i >= y). If one of these moves leaves a losing position for the opponent (wins[i - move] is false), the player wins.
-> If no move leads to a losing position for the opponent, the player loses.
-> Fill i from 1 up to n. If wins[n] is true, the first player A wins, otherwise B wins.
-> Let n be the number of coins. For each value of i we try at most 3 moves, so the time is n.
-> The wins array has n + 1 values, so the space is n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

char coinGameWinner(int n, int x, int y)
{
    vector<bool> wins(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (wins[i - 1] == false)
        {
            wins[i] = true;
        }
        else if (i >= x && wins[i - x] == false)
        {
            wins[i] = true;
        }
        else if (i >= y && wins[i - y] == false)
        {
            wins[i] = true;
        }
    }

    if (wins[n])
    {
        return 'A';
    }

    return 'B';
}

int main()
{
    int n = 5;
    int x = 3;
    int y = 4;

    cout << coinGameWinner(n, x, y) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(n)
*/
