/*
QUESTION:-

You are given an input array and an output array, both having the same distinct
elements. Check whether the output array can be obtained from the input array
using one stack. You read the input array from left to right, push each element
on the stack, and you may pop the stack at any time to append the popped
element to the output.

Constraints:
1 <= n <= 100000
All the elements are distinct and both arrays contain the same elements.

Example 1:

Input:
input = [1,2,3]
output = [2,1,3]

Output:
true
(push 1, push 2, pop 2, pop 1, push 3, pop 3)

Example 2:

Input:
input = [1,2,3]
output = [3,1,2]

Output:
false
(after 3 is popped, the stack has 2 on top of 1, so 2 must come before 1)
*/

/*
APPROACH:-

-> Simulate the process with a real stack and a pointer j to the next element needed in the output array.
-> Push the input elements one by one. After each push, while the top of the stack is equal to output[j], pop it and move j forward. This pops as early as possible, which never hurts.
-> After all the input is pushed and all possible pops are done, the output is possible exactly when every element has been matched, which means j == n (the stack is empty).
-> Let N be the size of the arrays. Every element is pushed once and popped at most once, so the time is N.
-> The stack can hold up to N elements, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isStackPermutation(vector<int> &input, vector<int> &output)
{
    int n = input.size();
    stack<int> st;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        st.push(input[i]);

        while (!st.empty() && j < n && st.top() == output[j])
        {
            st.pop();
            j++;
        }
    }

    return j == n;
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<int> output = {2, 1, 3};

    bool answer = isStackPermutation(input, output);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
