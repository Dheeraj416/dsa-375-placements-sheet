/*
QUESTION:-

You are given an array where every element is the number of chocolates in one
packet, and a number m of students. Give exactly one packet to every student so
that the difference between the largest packet and the smallest packet given
away is as small as possible. Return that minimum difference. If there are fewer
packets than students, return -1.

Constraints:
1 <= packets.length <= 100000
1 <= m <= 100000
1 <= packets[i] <= 1000000000

Example 1:

Input:
packets = [7,3,2,4,9,12,56]
m = 3

Output:
2
(give the packets 3, 2 and 4: the largest is 4, the smallest is 2)

Example 2:

Input:
packets = [3,4,1,9,56,7,9,12]
m = 5

Output:
6
(give the packets 3, 4, 7, 9 and 9: the difference is 9 - 3 = 6)
*/

/*
APPROACH:-

-> To keep the difference small, the packets given to students should have nearly equal sizes, and nearly equal values sit next to each other in a sorted array.
-> Sort the packets in increasing order.
-> Any group of m packets with the smallest possible spread is m consecutive packets in the sorted array.
-> So slide a window of size m over the sorted array. For the window starting at i, the difference is packets[i + m - 1] - packets[i].
-> The answer is the smallest difference over all windows.
-> Edge case: if m is bigger than the number of packets, nobody can get a packet each, so return -1.
-> Let N be the number of packets. Sorting costs N * log N and the window pass costs N, so the time is N * log N.
-> Sorting is done in place and only a few variables are used, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(vector<int> &packets, int m)
{
    int n = packets.size();

    if (m > n)
    {
        return -1;
    }

    sort(packets.begin(), packets.end());

    int minDifference = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        int difference = packets[i + m - 1] - packets[i];
        minDifference = min(minDifference, difference);
    }

    return minDifference;
}

int main()
{
    vector<int> packets = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    int answer = chocolateDistribution(packets, m);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
