/*
QUESTION:-

You are given a linked list where every node has two pointers: next, which
points to the next node of the top level list, and bottom, which points to a
sorted linked list hanging below that node. Every bottom list is sorted in
ascending order. Flatten the structure into a single sorted list that is linked
only through the bottom pointers, and return its head.

Constraints:
1 <= number of top level nodes <= 50
1 <= length of each bottom list <= 50
1 <= Node.data <= 1000

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22    35
|           |     |
8           50    40
|                 |
30                45

Output:
5 7 8 10 19 20 22 28 30 35 40 45 50

Example 2:

Input:
1 -> 2
|    |
3    4

Output:
1 2 3 4
*/

/*
APPROACH:-

-> Every bottom list is already sorted, so flattening is the same as merging sorted lists using the bottom pointer.
-> Recursively flatten everything to the right of the current node, then merge the current bottom list with that result.
-> The base case is a list with zero or one top level nodes, which is already flat.
-> Merging two sorted bottom lists works like merging two sorted linked lists: attach the smaller node each time.
-> Let N be the number of top level nodes and M the average length of a bottom list.
-> Merging from the right means each merge walks over the already merged nodes, so the total work is about N * N * M.
-> The recursion goes N levels deep, which is the extra space used.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

Node *buildBottomList(vector<int> &values)
{
    Node *head = new Node(values[0]);
    Node *tail = head;

    for (int i = 1; i < (int)values.size(); i++)
    {
        tail->bottom = new Node(values[i]);
        tail = tail->bottom;
    }

    return head;
}

Node *mergeBottomLists(Node *first, Node *second)
{
    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (first != nullptr && second != nullptr)
    {
        if (first->data <= second->data)
        {
            tail->bottom = first;
            first = first->bottom;
        }
        else
        {
            tail->bottom = second;
            second = second->bottom;
        }

        tail = tail->bottom;
    }

    if (first != nullptr)
    {
        tail->bottom = first;
    }
    else
    {
        tail->bottom = second;
    }

    Node *mergedHead = dummy->bottom;
    delete dummy;
    return mergedHead;
}

Node *flatten(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *mergedRest = flatten(head->next);

    return mergeBottomLists(head, mergedRest);
}

int main()
{
    vector<int> firstValues = {5, 7, 8, 30};
    vector<int> secondValues = {10, 20};
    vector<int> thirdValues = {19, 22, 50};
    vector<int> fourthValues = {28, 35, 40, 45};

    Node *head = buildBottomList(firstValues);
    head->next = buildBottomList(secondValues);
    head->next->next = buildBottomList(thirdValues);
    head->next->next->next = buildBottomList(fourthValues);

    Node *flat = flatten(head);

    while (flat != nullptr)
    {
        cout << flat->data << " ";
        flat = flat->bottom;
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N * M)
SPACE COMPLEXITY = O(N)
*/
