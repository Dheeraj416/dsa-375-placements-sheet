/*
QUESTION:-

In a game a player can score 3, 5 or 10 points in one move. Given a total score
n, count the number of distinct combinations of moves that give exactly n
points. Two combinations are the same if they use every kind of move the same
number of times (the order of the moves does not matter).

Constraints:
1 <= n <= 1000

Example 1:

Input:
n = 13

Output:
2
(3 + 10 and 3 + 5 + 5)

Example 2:

Input:
n = 20

Output:
4
(10 + 10, 10 + 5 + 5, 5 + 5 + 5 + 5, and 3 + 3 + 3 + 3 + 3 + 5)
*/

/*
APPROACH:-

-> This is the "count the combinations of coins" problem, where the coins are 3, 5 and 10 and the amount is n.
-> Let ways[s] be the number of combinations that give the score s. ways[0] = 1, because there is exactly one way to make 0 points: make no move.
-> Take the moves one kind at a time (first all the 3s, then the 5s, then the 10s). For one kind of move m, go through the scores from m up to n and add ways[s - m] to ways[s].
-> Going through the kinds in an outer loop means that a combination is counted once, no matter in which order its moves are made. If we put the scores in the outer loop, the same moves in a different order would be counted again.
-> The answer is ways[n].
-> There are only 3 kinds of moves, and for each one we go through at most n scores, so the time is n.
-> We keep one value for every score, so the space is n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countWays(int target)
{
    int moves[3] = {3, 5, 10};

    vector<long long> ways(target + 1, 0);
    ways[0] = 1;

    for (int m = 0; m < 3; m++)
    {
        for (int score = moves[m]; score <= target; score++)
        {
            ways[score] = ways[score] + ways[score - moves[m]];
        }
    }

    return ways[target];
}

int main()
{
    int n = 13;

    cout << countWays(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n)
SPACE COMPLEXITY = O(n)
*/
