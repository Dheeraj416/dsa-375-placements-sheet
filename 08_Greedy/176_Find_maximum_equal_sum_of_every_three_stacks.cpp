/*
QUESTION:-

You are given three stacks of positive integers. You may remove elements only
from the top of any stack, as many times as you like (even zero times). Find the
maximum possible sum that the three stacks can have after the removals, such
that the sums of all the three stacks are equal. If it is not possible to make
them equal (the sums can only be equal at 0), return 0. The stacks are given as
arrays whose first element is the top of the stack.

Constraints:
1 <= size of each stack <= 100000
1 <= element <= 1000

Example 1:

Input:
stack1 = [3,2,1,1,1]
stack2 = [4,3,2]
stack3 = [1,1,4,1]

Output:
5
(remove 3 from stack1, 4 from stack2, and 1, 1 from stack3: all sums become 5)

Example 2:

Input:
stack1 = [1,1,1]
stack2 = [1,1]
stack3 = [1]

Output:
1
*/

/*
APPROACH:-

-> Calculate the sum of every stack. We want the largest common sum, so we remove as little as possible.
-> If the three sums are equal, that sum is the answer.
-> Otherwise the stack with the largest sum cannot keep its current sum (it is bigger than another one), so we must remove its top element. Remove it and subtract it from that stack's sum.
-> Repeat. Always removing from the stack with the largest sum never removes more than needed, so the first time the three sums are equal, it is the maximum possible.
-> If any stack becomes empty, the only common sum is 0, so return 0.
-> Let N1, N2 and N3 be the sizes of the stacks. Each element is removed at most once, so the time is N1 + N2 + N3.
-> We only keep three sums and three indexes, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxEqualSum(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3)
{
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for (int i = 0; i < (int)stack1.size(); i++)
    {
        sum1 += stack1[i];
    }
    for (int i = 0; i < (int)stack2.size(); i++)
    {
        sum2 += stack2[i];
    }
    for (int i = 0; i < (int)stack3.size(); i++)
    {
        sum3 += stack3[i];
    }

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    while (true)
    {
        if (top1 == (int)stack1.size() || top2 == (int)stack2.size() || top3 == (int)stack3.size())
        {
            return 0;
        }

        if (sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= stack1[top1];
            top1++;
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= stack2[top2];
            top2++;
        }
        else
        {
            sum3 -= stack3[top3];
            top3++;
        }
    }
}

int main()
{
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    cout << maxEqualSum(stack1, stack2, stack3) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N1 + N2 + N3)
SPACE COMPLEXITY = O(1)
*/
