/*
QUESTION:-

You are given N items. Item i has a weight weights[i] and a value values[i]. You
have a bag that can carry a total weight of at most capacity. Every item can be
taken at most once (it is either taken completely or not taken). Return the
maximum total value you can put in the bag.

Constraints:
1 <= N <= 1000
1 <= weights[i] <= 1000
1 <= values[i] <= 1000
1 <= capacity <= 1000

Example 1:

Input:
weights = [1,2,4,5]
values = [5,4,8,6]
capacity = 5

Output:
13
(take the items with weights 1 and 4: value 5 + 8)

Example 2:

Input:
weights = [4,5,1]
values = [1,2,3]
capacity = 4

Output:
3
(take only the item with weight 1)
*/

/*
APPROACH:-

-> Let best[w] be the maximum value we can get with a bag of capacity w, using the items processed so far. At the start it is 0 for every w.
-> Process the items one by one. For an item with weight wt and value val, there are two choices for every capacity w: skip the item (best[w] stays the same) or take it (val + best[w - wt], which needs w >= wt).
-> We keep the larger of the two choices: best[w] = max(best[w], best[w - wt] + val).
-> We go through the capacities from the biggest to the smallest, so that best[w - wt] still holds the value from BEFORE this item. This makes sure the item is used at most once.
-> If we went from small to large, the same item could be counted again and again, which would solve the unbounded knapsack instead.
-> The answer is best[capacity].
-> Let N be the number of items and W the capacity. Every item goes through W capacities, so the time is N * W.
-> The best array has W + 1 cells, so the space is W.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int capacity)
{
    vector<int> best(capacity + 1, 0);

    for (int item = 0; item < (int)weights.size(); item++)
    {
        for (int w = capacity; w >= weights[item]; w--)
        {
            best[w] = max(best[w], best[w - weights[item]] + values[item]);
        }
    }

    return best[capacity];
}

int main()
{
    vector<int> weights = {1, 2, 4, 5};
    vector<int> values = {5, 4, 8, 6};
    int capacity = 5;

    int answer = knapsack(weights, values, capacity);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * W)
SPACE COMPLEXITY = O(W)
*/
