/*
QUESTION:-

You are given two integer arrays first and second, both of size N, and an
integer K. Form sums by taking one element from each array (first[i] + second[j]
for any i and j). Return the K maximum sums in descending order.

Constraints:
1 <= N <= 100000
1 <= K <= min(N, 100000)
-100000 <= first[i], second[i] <= 100000

Example 1:

Input:
first = [1,4,2,3], second = [2,5,1,6], K = 4

Output:
[10,9,9,8]

Example 2:

Input:
first = [3,2], second = [1,4], K = 2

Output:
[7,6]
*/

/*
APPROACH:-

-> Sort both arrays in descending order. The largest possible sum is first[0] + second[0].
-> Use a max heap that stores triples (sum, i, j). Start by pushing the largest sum with i = 0 and j = 0.
-> Repeat K times: take the largest sum out of the heap and add it to the answer.
-> The next candidates after the pair (i, j) are (i + 1, j) and (i, j + 1), because the arrays are sorted in descending order and these sums are the next smaller ones.
-> Push these two neighbours into the heap, unless they were already pushed. A set of visited pairs avoids pushing the same pair twice.
-> The heap and the set hold at most about 2K entries, so every step costs log K.
-> Sorting the arrays costs N log N, and the K steps cost K log K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumCombinations(vector<int> &first, vector<int> &second, int k)
{
    int n = (int)first.size();

    sort(first.begin(), first.end(), greater<int>());
    sort(second.begin(), second.end(), greater<int>());

    priority_queue<vector<int>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push({first[0] + second[0], 0, 0});
    visited.insert({0, 0});

    vector<int> answer;

    for (int count = 0; count < k; count++)
    {
        vector<int> top = maxHeap.top();
        maxHeap.pop();

        int sum = top[0];
        int i = top[1];
        int j = top[2];

        answer.push_back(sum);

        if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
        {
            maxHeap.push({first[i + 1] + second[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
        {
            maxHeap.push({first[i] + second[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }

    return answer;
}

int main()
{
    vector<int> first = {1, 4, 2, 3};
    vector<int> second = {2, 5, 1, 6};
    int k = 4;

    vector<int> answer = maxSumCombinations(first, second, k);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N + K * log K)
SPACE COMPLEXITY = O(K)
*/
