/*
QUESTION:-

Given the price of a share on each day, find the maximum profit you can make by
buying and selling the share at most twice. You must sell the share before you
buy it again, and you can hold only one share at a time.

Constraints:
1 <= prices.length <= 100000
0 <= prices[i] <= 100000

Example 1:

Input:
prices = [10,22,5,75,65,80]

Output:
87
(buy at 10 and sell at 22, then buy at 5 and sell at 80)

Example 2:

Input:
prices = [2,30,15,10,8,25,80]

Output:
100
(buy at 2 and sell at 30, then buy at 8 and sell at 80)
*/

/*
APPROACH:-

-> Go through the prices once and keep four numbers. buy1 is the best balance after the first buy (the money we have after paying for the share, so it is negative). sell1 is the best profit after the first sell.
-> buy2 is the best balance after the second buy (the profit of the first trade, minus the price of the second share). sell2 is the best profit after the second sell.
-> For every price p, update them in this order: buy1 = max(buy1, -p), sell1 = max(sell1, buy1 + p), buy2 = max(buy2, sell1 - p), sell2 = max(sell2, buy2 + p).
-> Each number uses the one before it, so the second trade can only start after the profit of the first trade is known. If one trade is enough, sell2 is the same as sell1, so "at most twice" is handled without any special case.
-> Start with buy1 and buy2 equal to minus the first price, and sell1 and sell2 equal to 0.
-> The answer is sell2.
-> Let N be the number of days. We make one pass, so the time is N.
-> Only four variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfitTwice(vector<int> &prices)
{
    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;

    for (int i = 1; i < (int)prices.size(); i++)
    {
        int p = prices[i];

        buy1 = max(buy1, -p);
        sell1 = max(sell1, buy1 + p);
        buy2 = max(buy2, sell1 - p);
        sell2 = max(sell2, buy2 + p);
    }

    return sell2;
}

int main()
{
    vector<int> prices = {10, 22, 5, 75, 65, 80};

    cout << maxProfitTwice(prices) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
