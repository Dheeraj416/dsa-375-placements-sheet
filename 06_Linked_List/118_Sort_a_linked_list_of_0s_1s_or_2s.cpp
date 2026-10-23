/*
QUESTION:-

Given a singly linked list whose nodes contain only the values 0, 1 and 2, sort
the list in increasing order and return its head.

Constraints:
1 <= number of nodes <= 100000
0 <= Node.val <= 2

Example 1:

Input:
head = [1,2,2,1,2,0,2,2]

Output:
[0,1,1,2,2,2,2,2]

Example 2:

Input:
head = [2,2,0,1]

Output:
[0,1,2,2]
*/

/*
APPROACH:-

-> There are only three different values, so we can simply count them.
-> Walk through the list once and count how many 0s, 1s and 2s there are in zeros, ones and twos.
-> Walk through the list a second time and overwrite the node values: first zeros nodes get 0, the next ones nodes get 1 and the remaining nodes get 2.
-> No node is created or deleted, only the values change.
-> Let N be the number of nodes. Two passes cost 2 * N, so the time is N.
-> We only use three counters, so the space is constant.
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

ListNode *sortList(ListNode *head)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->val == 0)
        {
            zeros++;
        }
        else if (current->val == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr)
    {
        if (zeros > 0)
        {
            current->val = 0;
            zeros--;
        }
        else if (ones > 0)
        {
            current->val = 1;
            ones--;
        }
        else
        {
            current->val = 2;
            twos--;
        }
        current = current->next;
    }

    return head;
}

int main()
{
    vector<int> values = {1, 2, 2, 1, 2, 0, 2, 2};
    ListNode *head = buildList(values);

    head = sortList(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
