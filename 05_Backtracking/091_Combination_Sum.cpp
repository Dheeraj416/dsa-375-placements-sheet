/*
QUESTION:-

Given an array of distinct integers candidates and a target integer, return all
the unique combinations of candidates whose sum is equal to target. The same
number may be chosen from candidates an unlimited number of times. Two
combinations are different if the frequency of at least one chosen number is
different.

Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
1 <= target <= 40

Example 1:

Input:
candidates = [2,3,6,7], target = 7

Output:
[[2,2,3],[7]]

Example 2:

Input:
candidates = [2,3,5], target = 8

Output:
[[2,2,2,2],[2,3,3],[3,5]]
*/

/*
APPROACH:-

-> Sort the candidates so we can stop early when a candidate is larger than the remaining target.
-> Use recursion with a start index and the remaining target.
-> If the remaining target is 0, the current list is a valid combination, so store it.
-> Try every candidate from the start index onwards. Add it, and recurse with the same index because a number can be reused.
-> Never go back to earlier indices, so the same combination is not generated in a different order.
-> After the recursive call, remove the last number (backtrack) and try the next candidate.
-> Break the loop as soon as a candidate is greater than the remaining target, since later candidates are even larger.
-> Let T be the target and K the average length of a combination. About 2^T combinations may be explored, copying one costs K, and the recursion goes at most T levels deep.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector<int> &candidates, int start, int remaining, vector<int> &current, vector<vector<int>> &answer)
{
    if (remaining == 0)
    {
        answer.push_back(current);
        return;
    }

    for (int i = start; i < (int)candidates.size(); i++)
    {
        if (candidates[i] > remaining)
        {
            break;
        }

        current.push_back(candidates[i]);
        findCombinations(candidates, i, remaining - candidates[i], current, answer);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> answer;
    vector<int> current;

    sort(candidates.begin(), candidates.end());
    findCombinations(candidates, 0, target, current, answer);

    return answer;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> answer = combinationSum(candidates, target);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            if (j > 0)
            {
                cout << ",";
            }
            cout << answer[i][j];
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^T * K)
SPACE COMPLEXITY = O(T)
*/
