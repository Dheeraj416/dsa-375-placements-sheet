/*
QUESTION:-

There are n friends. A matrix graph is given, where graph[i][j] is the amount of
money that friend i has to pay to friend j. Settle all the debts using the
minimum number of transactions. Print every transaction in the form
"Person X pays A to Person Y". When there is a tie while choosing a person, take
the one with the smaller index.

Constraints:
1 <= n <= 100
0 <= graph[i][j] <= 100000, and graph[i][i] = 0

Example 1:

Input:
graph =
0 1000 2000
0 0 5000
0 0 0

Output:
Person 1 pays 4000 to Person 2
Person 0 pays 3000 to Person 2

Example 2:

Input:
graph =
0 0 0
20 0 0
0 10 0

Output:
Person 1 pays 10 to Person 0
Person 2 pays 10 to Person 0
*/

/*
APPROACH:-

-> First calculate the net amount of every person: amount[i] = (money i should receive) - (money i should pay). A positive amount means the person is a creditor and a negative amount means a debtor.
-> The net amounts decide everything, because it does not matter who owed whom in the original matrix. The sum of all the net amounts is 0.
-> Greedy step: find the person with the maximum amount (maxCredit) and the person with the minimum amount (maxDebit). The debtor pays the smaller of the two absolute values to the creditor. This settles at least one of them completely.
-> Update the two amounts, print the transaction, and repeat until all the amounts are 0.
-> Each step settles at least one person, so there are at most n - 1 transactions.
-> Let N be the number of friends. Building the amounts costs N * N, and each of the at most N transactions needs a scan of N people, so the time is N * N.
-> The amount array takes N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void minimizeCashFlow(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> amount(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            amount[i] += graph[j][i] - graph[i][j];
        }
    }

    while (true)
    {
        int maxCredit = 0;
        int maxDebit = 0;

        for (int i = 0; i < n; i++)
        {
            if (amount[i] > amount[maxCredit])
            {
                maxCredit = i;
            }
            if (amount[i] < amount[maxDebit])
            {
                maxDebit = i;
            }
        }

        if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
        {
            break;
        }

        int pay = min(-amount[maxDebit], amount[maxCredit]);

        amount[maxCredit] -= pay;
        amount[maxDebit] += pay;

        cout << "Person " << maxDebit << " pays " << pay << " to Person " << maxCredit << "\n";
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 1000, 2000}, {0, 0, 5000}, {0, 0, 0}};

    minimizeCashFlow(graph);

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
