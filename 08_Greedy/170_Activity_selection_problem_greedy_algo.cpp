/*
QUESTION:-

You are given N activities with their start times and finish times. A person
can do only one activity at a time. Select the maximum number of activities
that can be done by one person, and print the indices of the selected
activities. An activity can start at the same moment the previous activity
finishes.

Constraints:
1 <= N <= 100000
0 <= start[i] < finish[i] <= 1000000000

Example 1:

Input:
start = [1,3,0,5,8,5], finish = [2,4,6,7,9,9]

Output:
0 1 3 4

Example 2:

Input:
start = [10,12,20], finish = [20,25,30]

Output:
0 2
*/

/*
APPROACH:-

-> Greedy idea: always select the activity that finishes earliest among the activities that do not clash with the last chosen one.
-> Keep each activity together with its original index and sort the activities by finish time.
-> Select the first activity and remember its finish time.
-> For every later activity, if its start time is greater than or equal to the last finish time, select it and update the finish time.
-> An earlier finish leaves the maximum room for the remaining activities, so the greedy choice is always safe.
-> Ties in finish time are broken by index, so the printed answer is the same every time.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int finish;
    int index;
};

bool compareByFinish(const Activity &first, const Activity &second)
{
    if (first.finish != second.finish)
    {
        return first.finish < second.finish;
    }

    return first.index < second.index;
}

vector<int> selectActivities(vector<int> &start, vector<int> &finish)
{
    vector<Activity> activities;

    for (int i = 0; i < (int)start.size(); i++)
    {
        activities.push_back({start[i], finish[i], i});
    }

    sort(activities.begin(), activities.end(), compareByFinish);

    vector<int> selected;
    selected.push_back(activities[0].index);
    int lastFinish = activities[0].finish;

    for (int i = 1; i < (int)activities.size(); i++)
    {
        if (activities[i].start >= lastFinish)
        {
            selected.push_back(activities[i].index);
            lastFinish = activities[i].finish;
        }
    }

    return selected;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    vector<int> answer = selectActivities(start, finish);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N)
SPACE COMPLEXITY = O(N)
*/
