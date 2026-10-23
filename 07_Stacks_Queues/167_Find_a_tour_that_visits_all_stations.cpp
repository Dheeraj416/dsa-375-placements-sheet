/*
QUESTION:-

There are n gas stations arranged in a circle. At station i you can fill
gas[i] units of gas, and it costs cost[i] units of gas to travel from station i
to the next station i + 1 (the last station is followed by station 0). Your car
has an empty tank at the start and the tank has no limit. Find the index of the
station from which you can start and travel around the circle once, visiting all
the stations. If it is not possible return -1. If a solution exists, it is
unique.

Constraints:
1 <= n <= 100000
0 <= gas[i], cost[i] <= 10000

Example 1:

Input:
gas = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output:
3
(start at station 3: 4-1=3, 3+5-2=6, 6+1-3=4, 4+2-4=2, 2+3-5=0)

Example 2:

Input:
gas = [2,3,4]
cost = [3,4,3]

Output:
-1
(the total gas is 9 and the total cost is 10)
*/

/*
APPROACH:-

-> Let balance[i] = gas[i] - cost[i], and look at the running sum of balance from station 0. Let prefix[i] be the sum of balance[0..i].
-> If the total sum is negative, there is not enough gas for the whole circle, so the answer is -1.
-> Otherwise find the position where the running sum is the lowest (use the first such position). If we start right after that position, the running sum never goes below the starting level, because we begin from the deepest valley. So the answer is (lowestIndex + 1) % n.
-> If the running sum never goes below 0, the lowest position is "before station 0", so the answer is 0.
-> In the code: lowest = 0 and lowestIndex = -1 at the start. For every station add its balance to the running sum; if the running sum is smaller than lowest, store it in lowest and store the index in lowestIndex.
-> Let N be the number of stations. We make one pass, so the time is N.
-> We only use a few variables, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findTour(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int runningSum = 0;
    int lowest = 0;
    int lowestIndex = -1;

    for (int i = 0; i < n; i++)
    {
        runningSum += gas[i] - cost[i];

        if (runningSum < lowest)
        {
            lowest = runningSum;
            lowestIndex = i;
        }
    }

    if (runningSum < 0)
    {
        return -1;
    }

    return (lowestIndex + 1) % n;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << findTour(gas, cost) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
