/*
QUESTION:-

You are given an array and several queries. Each query is a pair (L, R) and asks
for the number of distinct elements in the subarray from index L to index R
(both included). Answer all the queries efficiently using Mo's algorithm
(square root decomposition of the queries).

Constraints:
1 <= arr.length, queries.length <= 100000
0 <= arr[i] <= 1000000
0 <= L <= R < arr.length

Example 1:

Input:
arr = [1,1,2,1,3]
queries = [[0,4],[1,3],[2,4]]

Output:
[3,2,3]

Example 2:

Input:
arr = [5,5,5,5]
queries = [[0,3],[1,2]]

Output:
[1,1]
*/

/*
APPROACH:-

-> Answering every query with its own loop costs N for each query, which is too slow. Mo's algorithm reorders the queries so that moving from one query to the next needs very few steps.
-> Split the array positions into blocks of size about sqrt(N). Sort the queries by the block of L, and inside one block by R in increasing order.
-> Keep a current window [curL, curR] and a frequency array freq of the values inside the window, together with the count of distinct values.
-> To answer the next query, move the window edges one step at a time: adding an element increases its frequency (a new distinct value appears when the frequency becomes 1), removing an element decreases it (a distinct value disappears when the frequency becomes 0).
-> Inside one block, R only moves forward, so it moves at most N in total per block, and L moves at most sqrt(N) per query. This gives about (N + Q) * sqrt(N) pointer moves.
-> Store each answer at the original index of the query, because the queries were sorted.
-> Let N be the array size, Q the number of queries and M the maximum value in the array. The time is (N + Q) * sqrt(N).
-> The frequency array takes M, the queries and answers take Q, so the space is M + Q.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int left;
    int right;
    int index;
};

int blockSize = 1;

bool compareQueries(const Query &first, const Query &second)
{
    int firstBlock = first.left / blockSize;
    int secondBlock = second.left / blockSize;

    if (firstBlock != secondBlock)
    {
        return firstBlock < secondBlock;
    }

    return first.right < second.right;
}

vector<int> distinctInRanges(vector<int> &arr, vector<vector<int>> &ranges)
{
    int n = arr.size();
    blockSize = max(1, (int)sqrt(n));

    vector<Query> queries;

    for (int i = 0; i < (int)ranges.size(); i++)
    {
        Query query;
        query.left = ranges[i][0];
        query.right = ranges[i][1];
        query.index = i;
        queries.push_back(query);
    }

    sort(queries.begin(), queries.end(), compareQueries);

    int maxValue = *max_element(arr.begin(), arr.end());
    vector<int> freq(maxValue + 1, 0);
    vector<int> answers(ranges.size(), 0);

    int currentLeft = 0;
    int currentRight = -1;
    int distinct = 0;

    for (Query &query : queries)
    {
        while (currentLeft > query.left)
        {
            currentLeft--;
            freq[arr[currentLeft]]++;
            if (freq[arr[currentLeft]] == 1)
            {
                distinct++;
            }
        }

        while (currentRight < query.right)
        {
            currentRight++;
            freq[arr[currentRight]]++;
            if (freq[arr[currentRight]] == 1)
            {
                distinct++;
            }
        }

        while (currentLeft < query.left)
        {
            freq[arr[currentLeft]]--;
            if (freq[arr[currentLeft]] == 0)
            {
                distinct--;
            }
            currentLeft++;
        }

        while (currentRight > query.right)
        {
            freq[arr[currentRight]]--;
            if (freq[arr[currentRight]] == 0)
            {
                distinct--;
            }
            currentRight--;
        }

        answers[query.index] = distinct;
    }

    return answers;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 3};
    vector<vector<int>> ranges = {{0, 4}, {1, 3}, {2, 4}};

    vector<int> answer = distinctInRanges(arr, ranges);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O((N + Q) * sqrt(N))
SPACE COMPLEXITY = O(M + Q)
*/
