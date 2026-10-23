/*
QUESTION:-

Every node of a linked list has two pointers: next, which points to the next
node of the same level, and child, which points to the head of another linked
list (or null). The child lists can have their own child lists. Flatten the
structure into a single level list, level by level: first all the nodes of the
top level, then all the nodes of the second level, then the third level, and so
on. Inside a level the original order is kept. After flattening, every child
pointer must be null.

Constraints:
1 <= total number of nodes <= 10000
1 <= Node.val <= 100000

Example 1:

Input:
Top level: 1 -> 2 -> 3
Child of 2: 4 -> 5
Child of 3: 6
Child of 4: 7 -> 8

Output:
[1,2,3,4,5,6,7,8]

Example 2:

Input:
Top level: 1 -> 2
Child of 1: 3 -> 4

Output:
[1,2,3,4]
*/

/*
APPROACH:-

-> Find the tail of the top level list. All the child lists will be attached after this tail, so the list grows at its end.
-> Walk through the list with a pointer called current, starting at the head.
-> If current has a child, attach the child list at the tail: tail->next = current->child. Then move tail to the last node of that child list, and set current->child = null.
-> Then move current to current->next and repeat. Since the attached nodes are part of the list now, they will also be visited later and their own children will be attached too.
-> This produces the level by level order: the top level first, then the children found in the order of their parents, and so on.
-> Let N be the total number of nodes. Every node is visited once by current and once while searching for a tail, so the time is N.
-> Only a few pointers are used, so the space is constant.
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
    Node *child;

    Node(int x)
    {
        val = x;
        next = nullptr;
        child = nullptr;
    }
};

Node *flattenList(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *current = head;
    while (current != nullptr)
    {
        if (current->child != nullptr)
        {
            tail->next = current->child;

            Node *temp = current->child;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            tail = temp;

            current->child = nullptr;
        }
        current = current->next;
    }

    return head;
}

void printNodes(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    Node *seven = new Node(7);
    Node *eight = new Node(8);

    one->next = two;
    two->next = three;
    two->child = four;
    four->next = five;
    three->child = six;
    four->child = seven;
    seven->next = eight;

    Node *head = flattenList(one);

    printNodes(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
