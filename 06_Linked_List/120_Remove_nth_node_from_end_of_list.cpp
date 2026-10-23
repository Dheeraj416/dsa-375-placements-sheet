/*
QUESTION:-

Given the head of a linked list, remove the n-th node from the end of the list
and return the head of the list.

Constraints:
1 <= number of nodes <= 30
1 <= n <= number of nodes

Example 1:

Input:
head = [1,2,3,4,5], n = 2

Output:
[1,2,3,5]

Example 2:

Input:
head = [1,2], n = 1

Output:
[1]
*/

/*
APPROACH:-

-> Use two pointers, fast and slow, both starting at a dummy node placed before the head.
-> First move fast forward exactly n steps, so the gap between fast and slow is n nodes.
-> Then move both pointers together until fast reaches the last node.
-> Now slow stands just before the node that must be removed.
-> Skip the node with slow->next = slow->next->next.
-> The dummy node handles the case where the head itself has to be removed.
-> The list is scanned only once.
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;

    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);
    int n = 2;

    ListNode *result = removeNthFromEnd(head, n);

    printList(result);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
