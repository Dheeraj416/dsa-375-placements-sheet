/*
QUESTION:-

You are given N items. Item i has a weight weights[i] and a value values[i]. You
have a bag that can carry a total weight of at most capacity. Every item can be
taken any number of times. Return the maximum total value you can put in the bag.

Constraints:
1 <= N <= 1000
1 <= weights[i] <= 1000
1 <= values[i] <= 1000
1 <= capacity <= 1000

Example 1:

Input:
weights = [2,1]
values = [1,1]
capacity = 3

Output:
3
(take the item with weight 1 three times)

Example 2:

Input:
weights = [1,3,4,5]
values = [10,40,50,70]
capacity = 8

Output:
110
(take the items with weights 3 and 5: value 40 + 70)
*/

/*
APPROACH:-

-> Let best[w] be the maximum value that can be put in a bag of capacity w. best[0] = 0 because an empty bag holds nothing.
-> To fill best[w], try every item. If the item fits (its weight is at most w), we can put it in the bag and use the best answer for the remaining space: best[w - weight] + value.
-> Because an item can be used again, the remaining space may use the same item again, so we do not need to remember which items were already taken.
-> best[w] is the maximum over all items that fit. Fill w from 1 up to capacity, so the smaller answers are ready when needed.
-> The answer is best[capacity].
-> Let N be the number of items and W the capacity. For every capacity from 1 to W we look at all N items, so the time is N * W.
-> We store one value for every capacity, so the space is W.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int> &weights, vector<int> &values, int capacity)
{
    vector<int> best(capacity + 1, 0);

    for (int w = 1; w <= capacity; w++)
    {
        for (int i = 0; i < (int)weights.size(); i++)
        {
            if (weights[i] <= w)
            {
                best[w] = max(best[w], best[w - weights[i]] + values[i]);
            }
        }
    }

    return best[capacity];
}

int main()
{
    vector<int> weights = {2, 1};
    vector<int> values = {1, 1};
    int capacity = 3;

    cout << unboundedKnapsack(weights, values, capacity) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * W)
SPACE COMPLEXITY = O(W)
*/
