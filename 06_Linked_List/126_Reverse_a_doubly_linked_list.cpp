/*
QUESTION:-

Given the head of a doubly linked list, reverse the list and return the new
head. Both the next and the prev pointers must be updated.

Constraints:
0 <= number of nodes <= 100000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [1,2,3,4]

Output:
[4,3,2,1]

Example 2:

Input:
head = [10]

Output:
[10]
*/

/*
APPROACH:-

-> In a doubly linked list every node has a prev and a next pointer. Reversing the list means swapping these two pointers in every node.
-> Walk through the list with a pointer called current. For each node swap current->prev and current->next.
-> After the swap, the old next pointer is stored in prev, so the next node to visit is current->prev.
-> Remember the last node we processed in newHead. When current becomes null, newHead is the old tail, which is the new head.
-> Let N be the number of nodes. Every node is processed once, so the time is N.
-> No extra memory is used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct DNode
{
    int val;
    DNode *prev;
    DNode *next;

    DNode(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};

DNode *buildDoubly(vector<int> &values)
{
    DNode *head = nullptr;
    DNode *tail = nullptr;

    for (int i = 0; i < (int)values.size(); i++)
    {
        DNode *node = new DNode(values[i]);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    return head;
}

void printDoubly(DNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

DNode *reverseDoubly(DNode *head)
{
    DNode *current = head;
    DNode *newHead = nullptr;

    while (current != nullptr)
    {
        DNode *temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        newHead = current;
        current = current->prev;
    }

    return newHead;
}

int main()
{
    vector<int> values = {1, 2, 3, 4};
    DNode *head = buildDoubly(values);

    head = reverseDoubly(head);

    printDoubly(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
