/*
QUESTION:-

Every node of a singly linked list has two pointers: next, which points to the
next node of the list, and arbit, which is initially null. Make the arbit
pointer of every node point to the node that has the next higher value in the
list (the smallest value that is greater than the value of the node). The arbit
pointer of the node with the largest value stays null. All the values in the
list are different. Print, for every node in list order, its value and the
value of the node its arbit pointer points to (-1 if it is null).

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000, all values are different

Example 1:

Input:
head = [5,10,2,3]

Output:
5 10
10 -1
2 3
3 5

Example 2:

Input:
head = [3,2,1]

Output:
3 -1
2 3
1 2
*/

/*
APPROACH:-

-> The node with the next higher value is just the next node when the nodes are arranged in sorted order.
-> Collect the addresses of all the nodes into a vector called nodes, in list order.
-> Make a copy of this vector and sort the copy by node value. The original list and its next pointers are not touched.
-> In the sorted copy, set sortedNodes[i]->arbit = sortedNodes[i + 1]. The last node in sorted order (largest value) gets null.
-> Finally walk through the original list and print each node's value with the value of its arbit node.
-> Let N be the number of nodes. Sorting costs N * log N, so the time is N * log N.
-> The two vectors of addresses take N space, so the space is N. (An in place merge sort on the list can reduce this to constant space, but it is harder to write.)
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *arbit;

    Node(int x)
    {
        val = x;
        next = nullptr;
        arbit = nullptr;
    }
};

bool compareNodes(Node *a, Node *b)
{
    return a->val < b->val;
}

void setArbitPointers(Node *head)
{
    vector<Node *> nodes;
    Node *current = head;
    while (current != nullptr)
    {
        nodes.push_back(current);
        current = current->next;
    }

    vector<Node *> sortedNodes = nodes;
    sort(sortedNodes.begin(), sortedNodes.end(), compareNodes);

    for (int i = 0; i < (int)sortedNodes.size(); i++)
    {
        if (i + 1 < (int)sortedNodes.size())
        {
            sortedNodes[i]->arbit = sortedNodes[i + 1];
        }
        else
        {
            sortedNodes[i]->arbit = nullptr;
        }
    }
}

void printArbit(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        if (head->arbit != nullptr)
        {
            cout << head->arbit->val;
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
        head = head->next;
    }
}

int main()
{
    vector<int> values = {5, 10, 2, 3};

    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < (int)values.size(); i++)
    {
        Node *node = new Node(values[i]);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    setArbitPointers(head);

    printArbit(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
