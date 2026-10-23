/*
QUESTION:-

There is a singly linked list and you are given only a node that must be
deleted. You are not given the head of the list. The node to delete is
guaranteed not to be the last node. Delete the node from the list. The values
of the other nodes and their order must stay the same.

Constraints:
2 <= number of nodes <= 1000
The node to be deleted is in the list and is not the tail node.

Example 1:

Input:
head = [4,5,1,9], node = 5

Output:
[4,1,9]

Example 2:

Input:
head = [4,5,1,9], node = 1

Output:
[4,5,9]
*/

/*
APPROACH:-

-> We cannot reach the previous node, so we cannot unlink the given node in the usual way.
-> Instead, copy the value of the next node into the given node.
-> Then skip the next node by setting node->next = node->next->next.
-> The list now looks exactly as if the original node had been removed, because the next node's value took its place.
-> This is why the node must not be the tail: a tail has no next node to copy from.
-> Only a constant amount of work is done.
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

void deleteNode(ListNode *node)
{
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}

int main()
{
    vector<int> values = {4, 5, 1, 9};
    ListNode *head = buildList(values);

    ListNode *target = head;
    while (target->val != 5)
    {
        target = target->next;
    }

    deleteNode(target);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(1)
*/
