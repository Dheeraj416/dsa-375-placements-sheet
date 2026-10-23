/*
QUESTION:-

Given an amount V and the Indian currency denominations 1, 2, 5, 10, 20, 50,
100, 500 and 1000 (an unlimited number of coins and notes of each kind), find
the minimum number of coins and notes needed to make the amount V. Print the
count first and then the coins used, from largest to smallest.

Constraints:
1 <= V <= 100000

Example 1:

Input:
V = 49

Output:
5
20 20 5 2 2

Example 2:

Input:
V = 121

Output:
3
100 20 1
*/

/*
APPROACH:-

-> Greedy idea: always take the largest denomination that is not more than the remaining amount.
-> Keep the denominations in sorted order and start checking from the largest one.
-> While the remaining amount is at least the current denomination, take that coin and subtract its value.
-> Then move on to the next smaller denomination.
-> This is correct for these denominations because every denomination is large enough that using the biggest one first never wastes coins.
-> Let D be the number of denominations (9) and C be the number of coins used in the answer.
-> The result list stores the C coins that were picked.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minimumCoins(int amount)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> coinsUsed;

    for (int i = (int)denominations.size() - 1; i >= 0; i--)
    {
        while (amount >= denominations[i])
        {
            amount -= denominations[i];
            coinsUsed.push_back(denominations[i]);
        }
    }

    return coinsUsed;
}

int main()
{
    int amount = 49;

    vector<int> coins = minimumCoins(amount);

    cout << coins.size() << "\n";

    for (int x : coins)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(D + C)
SPACE COMPLEXITY = O(C)
*/
