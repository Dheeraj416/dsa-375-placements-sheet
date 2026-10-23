/*
QUESTION:-

Given an integer array nums and an integer k, return the k most frequent
elements. The answer is printed from the most frequent element to the least
frequent one. It is guaranteed that the answer is unique.

Constraints:
1 <= nums.length <= 100000
-10000 <= nums[i] <= 10000
k is in the range [1, number of distinct elements]

Example 1:

Input:
nums = [1,1,1,2,2,3], k = 2

Output:
[1,2]

Example 2:

Input:
nums = [1], k = 1

Output:
[1]
*/

/*
APPROACH:-

-> First count how many times every number appears using a hash map from number to frequency.
-> Then keep a min heap of size at most k that holds pairs (frequency, number). The heap compares the frequency first.
-> For every entry of the map push the pair into the heap. If the heap has more than k pairs, remove the top pair, which is the one with the smallest frequency.
-> After all the entries are processed, the heap holds exactly the k most frequent numbers.
-> Taking them out of the heap gives them from the least frequent to the most frequent, so reverse the answer at the end.
-> Counting takes O(N). Each of the at most N distinct numbers costs log K in the heap, so the total is N * log K.
-> The map needs up to N entries, so the space is O(N).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> frequency;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        frequency[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (unordered_map<int, int>::iterator it = frequency.begin(); it != frequency.end(); ++it)
    {
        minHeap.push({it->second, it->first});

        if ((int)minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> answer;

    while (!minHeap.empty())
    {
        answer.push_back(minHeap.top().second);
        minHeap.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> answer = topKFrequent(nums, k);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(N)
*/
