/*
QUESTION:-

There are n petrol pumps arranged in a circle. For every pump you know the
amount of petrol it gives, petrol[i], and the distance from this pump to the
next pump, distance[i]. A truck with an unlimited tank uses 1 unit of petrol per
1 unit of distance. Find the index of the first petrol pump from where the truck
can start and complete the full circle visiting all the pumps in order. If it is
not possible, return -1.

Constraints:
1 <= n <= 100000
1 <= petrol[i], distance[i] <= 10000

Example 1:

Input:
petrol = [4,6,7,4]
distance = [6,5,3,5]

Output:
1
(start at pump 1: 6-5=1, 1+7-3=5, 5+4-5=4, 4+4-6=2, never negative)

Example 2:

Input:
petrol = [2,3,4]
distance = [3,4,5]

Output:
-1
(the total petrol is 9 and the total distance is 12)
*/

/*
APPROACH:-

-> If the total petrol is less than the total distance, no start works, so the answer is -1.
-> Otherwise a valid start exists. Use a greedy scan. Keep tank, the petrol left while travelling from the current candidate start.
-> At every pump i add petrol[i] - distance[i] to the tank. If the tank becomes negative, the truck cannot reach pump i + 1 from the current start, and it cannot reach it from any pump between the start and i either (they all arrived with at least 0 petrol). So make i + 1 the new candidate start and reset the tank to 0.
-> Also keep a total of all the gains. If the total is negative at the end, return -1. Otherwise the candidate start is the answer.
-> Let N be the number of pumps. We make one pass, so the time is N.
-> We only use a few variables, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int circularTour(vector<int> &petrol, vector<int> &distance)
{
    int n = petrol.size();
    int total = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        int gain = petrol[i] - distance[i];
        total += gain;
        tank += gain;

        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    if (total < 0)
    {
        return -1;
    }

    return start;
}

int main()
{
    vector<int> petrol = {4, 6, 7, 4};
    vector<int> distance = {6, 5, 3, 5};

    cout << circularTour(petrol, distance) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
