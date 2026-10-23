/*
QUESTION:-

Given an array of integers and a number diff, check whether there are two
elements (at different positions) whose difference is exactly diff. Return true
if such a pair exists, otherwise return false.

Constraints:
2 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000
0 <= diff <= 1000000000

Example 1:

Input:
arr = [5,20,3,2,50,80]
diff = 78

Output:
true
(80 - 2 = 78)

Example 2:

Input:
arr = [90,70,20,80,50]
diff = 45

Output:
false
*/

/*
APPROACH:-

-> A pair (x, y) has the difference diff when y = x + diff or x = y + diff. So for every element x we need to know if x + diff or x - diff was seen earlier.
-> Use a hash set of the elements seen so far.
-> For each element x, check if x + diff or x - diff is in the set. If yes, a pair exists, so return true.
-> Otherwise insert x into the set and continue. We insert only after the check, so an element is never paired with itself. When diff is 0, the answer is true only if some value appears twice, which this method handles correctly.
-> If no pair is found, return false.
-> Let N be the size of the array. Each element needs a constant number of set operations, so the time is N.
-> The set holds up to N elements, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool hasPairWithDifference(vector<int> &arr, int diff)
{
    unordered_set<long long> seen;

    for (int x : arr)
    {
        if (seen.find((long long)x + diff) != seen.end() || seen.find((long long)x - diff) != seen.end())
        {
            return true;
        }

        seen.insert(x);
    }

    return false;
}

int main()
{
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int diff = 78;

    bool answer = hasPairWithDifference(arr, diff);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
