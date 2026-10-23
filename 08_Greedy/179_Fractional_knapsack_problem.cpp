/*
QUESTION:-

You are given N items, each with a value and a weight, and a knapsack with
capacity W. You may take a fraction of an item. Find the maximum total value
that can be put in the knapsack.

Constraints:
1 <= N <= 100000
1 <= value[i], weight[i], W <= 10000

Example 1:

Input:
values = [60,100,120], weights = [10,20,30], W = 50

Output:
240.00
Explanation: Take the first two items fully and two thirds of the third item.

Example 2:

Input:
values = [500], weights = [30], W = 10

Output:
166.67
*/

/*
APPROACH:-

-> Greedy idea: the best item is the one that gives the most value per unit of weight.
-> Sort the items in decreasing order of value / weight.
-> Take items one by one. If the whole item fits in the remaining capacity, take all of it.
-> If it does not fit, take only the fraction that fits, add its proportional value and stop, because the knapsack is full.
-> This works because we can split items, so filling space with the best ratio first can never be improved.
-> Use double for the value because fractions are allowed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compareByRatio(const Item &first, const Item &second)
{
    double firstRatio = (double)first.value / first.weight;
    double secondRatio = (double)second.value / second.weight;
    return firstRatio > secondRatio;
}

double fractionalKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compareByRatio);

    double totalValue = 0.0;
    int remaining = capacity;

    for (int i = 0; i < (int)items.size(); i++)
    {
        if (items[i].weight <= remaining)
        {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        }
        else
        {
            totalValue += (double)items[i].value * remaining / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    double answer = fractionalKnapsack(items, capacity);

    cout << fixed << setprecision(2) << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N)
SPACE COMPLEXITY = O(1)
*/
