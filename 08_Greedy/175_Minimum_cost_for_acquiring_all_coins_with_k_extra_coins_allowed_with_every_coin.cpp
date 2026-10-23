/*
QUESTION:-

There is a shop with n coins, and the i-th coin has a price arr[i]. Whenever you
buy a coin, you are allowed to take any k other coins for free. Find the minimum
total price you have to pay to acquire all the coins.

Constraints:
1 <= n <= 100000
0 <= k <= n - 1
1 <= arr[i] <= 100000

Example 1:

Input:
arr = [100,20,50,10,2,5]
k = 3

Output:
7
(buy the coin 2 and take 100, 50, 20 free; then buy 5 and take 10 free)

Example 2:

Input:
arr = [1,2,3,4,5]
k = 2

Output:
3
(buy 1 and take 5, 4 free; buy 2 and take 3 free)
*/

/*
APPROACH:-

-> Every time we pay for a coin, we should pick the cheapest coin that is still left to pay for it, and take the k most expensive coins that are still left for free.
-> Sort the prices in increasing order and use two pointers: i at the cheapest remaining coin and j at the most expensive remaining coin.
-> While i <= j: pay arr[i], move i forward by 1, and move j backward by k (these k coins are free).
-> The coins between i and j are the ones still not acquired. When the pointers cross, all the coins are acquired.
-> The total paid is the answer.
-> Let N be the number of coins. Sorting costs N * log N and the loop costs at most N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = (int)arr.size() - 1;
    int cost = 0;

    while (i <= j)
    {
        cost += arr[i];
        i++;
        j -= k;
    }

    return cost;
}

int main()
{
    vector<int> arr = {100, 20, 50, 10, 2, 5};
    int k = 3;

    cout << minimumCost(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
