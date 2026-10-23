/*
QUESTION:-

There are n ropes of given lengths. Connect all of them into one rope. The cost
of connecting two ropes is the sum of their lengths. Find the minimum total cost
of connecting all the ropes into one.

Constraints:
1 <= n <= 100000
1 <= length <= 1000000

Example 1:

Input:
ropes = [4,3,2,6]

Output:
29
(2+3=5, 4+5=9, 6+9=15, and 5+9+15=29)

Example 2:

Input:
ropes = [4,2,7,6,9]

Output:
62
(2+4=6, 6+6=12, 7+9=16, 12+16=28, and 6+12+16+28=62)
*/

/*
APPROACH:-

-> A rope that is connected early is counted again in every later connection that contains it. So the short ropes should be connected first, and the long ropes should be connected last.
-> Put all the lengths in a min heap. Repeat while the heap has at least 2 ropes: remove the two shortest ropes, add their sum to the total cost, and push the sum back into the heap as a new rope.
-> When only one rope remains, everything is connected and the total cost is the answer.
-> This is the same greedy idea as Huffman coding.
-> Use long long because the total can be larger than the int range.
-> Let N be the number of ropes. Each of the N - 1 steps does a few heap operations of cost log N, so the time is N * log N.
-> The heap holds up to N ropes, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int> &ropes)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < (int)ropes.size(); i++)
    {
        minHeap.push(ropes[i]);
    }

    long long total = 0;

    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();

        total += first + second;
        minHeap.push(first + second);
    }

    return total;
}

int main()
{
    vector<int> ropes = {4, 3, 2, 6};

    cout << minimumCost(ropes) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
