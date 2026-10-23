/*
QUESTION:-

A car factory has two assembly lines, and each line has n stations. The time
taken at station j of line i is a[i][j]. A car chassis enters a line i after
e[i] time units, and the finished car leaves line i after x[i] time units. A
car can stay on its line, or move from line i to the other line before station
j, which costs t[i][j] time units (the transfer time t[i][j] is paid when the car
arrives at station j coming from the other line; t[i][0] is never used). Return
the minimum total time to build one car.

Constraints:
1 <= n <= 1000
All times are non-negative integers.

Example 1:

Input:
a = [[4,5,3,2],[2,10,1,4]]
t = [[0,7,4,5],[0,9,2,8]]
e = [10,12]
x = [18,7]

Output:
35

Example 2:

Input:
a = [[4,5],[2,10]]
t = [[0,7],[0,9]]
e = [10,12]
x = [18,7]

Output:
31
*/

/*
APPROACH:-

-> Let line0 be the minimum time to finish the current station on line 0, and line1 the same for line 1. At station 0 they are e[0] + a[0][0] and e[1] + a[1][0].
-> To finish station j on line 0, the car either came from station j - 1 on line 0 (no transfer) or from station j - 1 on line 1 (and then paid the transfer time). So the new value is a[0][j] + min(line0, line1 + t[1][j]).
-> In the same way, the new value for line 1 is a[1][j] + min(line1, line0 + t[0][j]).
-> Compute both new values from the old values, and then replace the old values. Do this for every station.
-> At the end, the car leaves from one of the two lines, so the answer is min(line0 + x[0], line1 + x[1]).
-> Let N be the number of stations. We make one pass with constant work per station, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int assemblyLine(vector<vector<int>> &a, vector<vector<int>> &t, vector<int> &e, vector<int> &x)
{
    int n = a[0].size();

    int line0 = e[0] + a[0][0];
    int line1 = e[1] + a[1][0];

    for (int j = 1; j < n; j++)
    {
        int newLine0 = a[0][j] + min(line0, line1 + t[1][j]);
        int newLine1 = a[1][j] + min(line1, line0 + t[0][j]);

        line0 = newLine0;
        line1 = newLine1;
    }

    return min(line0 + x[0], line1 + x[1]);
}

int main()
{
    vector<vector<int>> a = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    vector<vector<int>> t = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    vector<int> e = {10, 12};
    vector<int> x = {18, 7};

    cout << assemblyLine(a, t, e, x) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
