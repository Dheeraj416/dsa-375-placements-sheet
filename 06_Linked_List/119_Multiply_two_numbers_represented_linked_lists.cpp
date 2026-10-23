/*
QUESTION:-

Two numbers are given as linked lists, where every node holds one digit and the
most significant digit is at the head. Multiply the two numbers and return the
product modulo 1000000007.

Constraints:
1 <= number of nodes in each list <= 100
0 <= Node.val <= 9

Example 1:

Input:
first = [9,4,6]
second = [8,4]

Output:
79464
(946 * 84 = 79464)

Example 2:

Input:
first = [3,2]
second = [2]

Output:
64
(32 * 2 = 64)
*/

/*
APPROACH:-

-> The numbers can have up to 100 digits, so they do not fit in a normal integer. We keep them modulo 1000000007 while reading them.
-> Read the first list from the head: number = (number * 10 + digit) % MOD. Do the same for the second list.
-> Taking the modulo while building is safe because (a * 10 + d) % MOD gives the same result as the full number modulo MOD.
-> Multiply the two remainders using long long, and take the modulo once more.
-> Let N and M be the sizes of the two lists. Reading them costs N + M, so the time is N + M.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *buildList(vector<int> &values)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    for (int i = 0; i < (int)values.size(); i++)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

long long multiplyLists(ListNode *first, ListNode *second)
{
    const long long MOD = 1000000007;
    long long firstNumber = 0;
    long long secondNumber = 0;

    while (first != nullptr)
    {
        firstNumber = (firstNumber * 10 + first->val) % MOD;
        first = first->next;
    }

    while (second != nullptr)
    {
        secondNumber = (secondNumber * 10 + second->val) % MOD;
        second = second->next;
    }

    return (firstNumber * secondNumber) % MOD;
}

int main()
{
    vector<int> firstValues = {9, 4, 6};
    vector<int> secondValues = {8, 4};
    ListNode *first = buildList(firstValues);
    ListNode *second = buildList(secondValues);

    cout << multiplyLists(first, second) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(1)
*/
