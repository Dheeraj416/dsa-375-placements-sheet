/*
QUESTION:-

Given an integer array of size n, find the maximum of the minimums of every
window size. For every window size k from 1 to n, look at all the windows of
size k, take the minimum of each window, and report the maximum among these
minimums. The answer is an array of n integers, where the k-th integer is the
result for window size k.

Constraints:
1 <= n <= 100000
-1000000 <= arr[i] <= 1000000

Example 1:

Input:
arr = [10,20,30,50,10,70,30]

Output:
[70,30,20,10,10,10,10]

Example 2:

Input:
arr = [10,20,30]

Output:
[30,20,10]
*/

/*
APPROACH:-

-> For every element arr[i], find how far it can stretch as the minimum: the nearest smaller element on its left (leftSmaller) and on its right (rightSmaller).
-> The element arr[i] is the minimum of a window of length rightSmaller - leftSmaller - 1, and of every smaller window inside that range.
-> Find leftSmaller and rightSmaller for all elements with a stack in linear time.
-> Store in answer[length] the largest arr[i] whose maximum window length is exactly length.
-> A value that is the minimum of a window of length L is also the minimum of some window of every smaller length, so go from the longest length to the shortest and keep answer[length] = max(answer[length], answer[length + 1]).
-> Positions that nobody filled get their value from this propagation, since the whole array has at least one minimum for window size n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfMinimums(vector<int> &arr)
{
    int n = (int)arr.size();
    vector<int> leftSmaller(n, -1);
    vector<int> rightSmaller(n, n);
    stack<int> indices;

    for (int i = 0; i < n; i++)
    {
        while (!indices.empty() && arr[indices.top()] >= arr[i])
        {
            indices.pop();
        }

        if (!indices.empty())
        {
            leftSmaller[i] = indices.top();
        }

        indices.push(i);
    }

    while (!indices.empty())
    {
        indices.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!indices.empty() && arr[indices.top()] >= arr[i])
        {
            indices.pop();
        }

        if (!indices.empty())
        {
            rightSmaller[i] = indices.top();
        }

        indices.push(i);
    }

    vector<int> best(n + 2, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        int length = rightSmaller[i] - leftSmaller[i] - 1;
        best[length] = max(best[length], arr[i]);
    }

    for (int length = n - 1; length >= 1; length--)
    {
        best[length] = max(best[length], best[length + 1]);
    }

    vector<int> answer;

    for (int length = 1; length <= n; length++)
    {
        answer.push_back(best[length]);
    }

    return answer;
}

int main()
{
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};

    vector<int> answer = maxOfMinimums(arr);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
