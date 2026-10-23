/*
QUESTION:-

Numbers arrive one by one in a stream. After each number arrives, print the
k-th largest element among all the numbers received so far. If fewer than k
numbers have arrived, print -1 for that position.

Constraints:
1 <= k <= 100000
1 <= number of stream elements <= 100000
1 <= element <= 1000000000

Example 1:

Input:
k = 4
stream = [1,2,3,4,5,6]

Output:
-1 -1 -1 1 2 3

Example 2:

Input:
k = 2
stream = [10,5,20]

Output:
-1 5 10
*/

/*
APPROACH:-

-> Keep a min heap that holds the k largest numbers received so far. Its top is the smallest of them, which is the k-th largest overall.
-> When a number arrives and the heap has fewer than k numbers, just push it.
-> Otherwise, compare it with the top. If it is larger than the top, the top is no longer among the k largest, so remove the top and push the new number. If it is not larger, ignore it.
-> After each arrival, if the heap still has fewer than k numbers the answer is -1, else the answer is the top of the heap.
-> Let N be the number of stream elements. Each arrival costs log K, so the time is N * log K.
-> The heap holds at most k numbers, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> kthLargestInStream(vector<int> &stream, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;

    for (int i = 0; i < (int)stream.size(); i++)
    {
        int x = stream[i];

        if ((int)minHeap.size() < k)
        {
            minHeap.push(x);
        }
        else if (x > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(x);
        }

        if ((int)minHeap.size() < k)
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(minHeap.top());
        }
    }

    return result;
}

int main()
{
    vector<int> stream = {1, 2, 3, 4, 5, 6};
    int k = 4;

    vector<int> answer = kthLargestInStream(stream, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
