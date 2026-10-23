/*
QUESTION:-

You are given some identical eggs and a building with a number of floors. There is
a floor f (0 <= f <= floors) such that an egg dropped from a floor higher than f
breaks, and an egg dropped from floor f or lower does not break. An egg that does
not break can be used again. Find the minimum number of drops needed, in the
worst case, to find f for sure.

Constraints:
1 <= eggs <= 10
1 <= floors <= 100

Example 1:

Input:
eggs = 2, floors = 10

Output:
4

Example 2:

Input:
eggs = 1, floors = 5

Output:
5
(with one egg we must go up floor by floor)
*/

/*
APPROACH:-

-> Let dp[e][f] be the minimum number of drops needed in the worst case with e eggs and f floors. With 0 floors no drop is needed, so dp[e][0] = 0. With 1 egg we must try the floors one by one, so dp[1][f] = f.
-> With e >= 2 eggs and f floors, try dropping an egg from every floor x between 1 and f.
-> If the egg breaks, we continue with e - 1 eggs and only the x - 1 floors below: dp[e - 1][x - 1].
-> If the egg does not break, we continue with all e eggs and the f - x floors above: dp[e][f - x].
-> We must be ready for the worse of the two cases, so the cost of choosing floor x is 1 + max(dp[e - 1][x - 1], dp[e][f - x]). We choose the floor with the smallest cost.
-> The answer is dp[eggs][floors].
-> Let E be the number of eggs and F the number of floors. The table has E * F cells and for each cell we try up to F floors, so the time is E * F * F.
-> The space for the table is E * F.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors)
{
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    for (int f = 1; f <= floors; f++)
    {
        dp[1][f] = f;
    }

    for (int e = 2; e <= eggs; e++)
    {
        for (int f = 1; f <= floors; f++)
        {
            dp[e][f] = INT_MAX;

            for (int x = 1; x <= f; x++)
            {
                int worst = 1 + max(dp[e - 1][x - 1], dp[e][f - x]);
                dp[e][f] = min(dp[e][f], worst);
            }
        }
    }

    return dp[eggs][floors];
}

int main()
{
    int eggs = 2;
    int floors = 10;

    cout << eggDrop(eggs, floors) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(E * F * F)
SPACE COMPLEXITY = O(E * F)
*/
