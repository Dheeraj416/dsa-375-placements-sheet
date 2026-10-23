/*
QUESTION:-

You are given an array of integers where every value is between 1 and 31. Print
all the values that appear more than once, each value printed once, in
increasing order. Do not use a boolean array or a hash set: use only integer
variables as bit sets to remember which values were seen. If no value is
repeated, print -1.

Constraints:
1 <= arr.length <= 100000
1 <= arr[i] <= 31

Example 1:

Input:
arr = [5,3,5,1,3,7,5]

Output:
3 5

Example 2:

Input:
arr = [1,2,3,4]

Output:
-1
*/

/*
APPROACH:-

-> A boolean array of size 32 wastes memory because every flag needs a whole byte. One 32 bit integer has 32 bits, so it can store 32 flags: bit v means "the value v was seen".
-> Keep two integers: seen (bit v is 1 if v appeared at least once) and repeated (bit v is 1 if v appeared at least twice).
-> For each value v, build the mask 1 << v. If seen already has that bit, set the same bit in repeated. In any case set the bit in seen.
-> After the pass, go through the bits 1 to 31 in increasing order and collect every v whose bit is set in repeated.
-> Setting a bit uses OR (|), and checking a bit uses AND (&) with the mask.
-> Let N be the size of the array. One pass over the array plus 31 checks gives a time of N.
-> Only two integers are used for the bookkeeping, so the space is constant (the answer list is not counted).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findRepeatedValues(vector<int> &arr)
{
    unsigned int seen = 0;
    unsigned int repeated = 0;

    for (int v : arr)
    {
        unsigned int mask = 1u << v;

        if (seen & mask)
        {
            repeated = repeated | mask;
        }

        seen = seen | mask;
    }

    vector<int> result;

    for (int v = 1; v <= 31; v++)
    {
        if (repeated & (1u << v))
        {
            result.push_back(v);
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {5, 3, 5, 1, 3, 7, 5};

    vector<int> answer = findRepeatedValues(arr);

    if (answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int x : answer)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
