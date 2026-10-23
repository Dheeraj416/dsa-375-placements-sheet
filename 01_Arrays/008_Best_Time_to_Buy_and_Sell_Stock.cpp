/*
QUESTION:-

You are given an array prices where prices[i] is the price of a stock on day i.
You may complete at most one transaction: buy on one day and sell on a later
day. Return the maximum profit. If no profit is possible, return 0.

Constraints:
1 <= prices.length <= 100000
0 <= prices[i] <= 10000

Example 1:

Input:
prices = [7,1,5,3,6,4]

Output:
5
Explanation: Buy on day 2 (price 1) and sell on day 5 (price 6).

Example 2:

Input:
prices = [7,6,4,3,1]

Output:
0
*/

/*
APPROACH:-

-> Traverse the prices from left to right.
-> Keep minPrice, the lowest price seen so far. This is the best day to have bought.
-> For every day, the profit if we sell today is prices[i] - minPrice.
-> Keep the maximum of these profits in bestProfit.
-> Update minPrice after checking the profit for the day.
-> If the prices only fall, no profit is ever positive, so the answer stays 0.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }

    int minPrice = prices[0];
    int bestProfit = 0;

    for (int i = 1; i < (int)prices.size(); i++)
    {
        bestProfit = max(bestProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return bestProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int answer = maxProfit(prices);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
