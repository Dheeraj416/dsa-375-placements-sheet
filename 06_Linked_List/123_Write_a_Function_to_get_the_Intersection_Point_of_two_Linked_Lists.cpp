/*
QUESTION:-

Given the heads of two singly linked lists headA and headB, return the node at
which the two lists intersect (the node itself must be shared, not only equal
in value). If the two lists have no intersection, return null. The lists must
keep their original structure after the function returns.

Constraints:
1 <= number of nodes in each list <= 30000
1 <= Node.val <= 100000

Example 1:

Input:
listA = [4,1,8,4,5], listB = [5,6,1,8,4,5] where the lists share the nodes 8,4,5

Output:
Intersected at the node with value 8

Example 2:

Input:
listA = [2,6,4], listB = [1,5] with no shared node

Output:
No intersection
*/

/*
APPROACH:-

-> Use two pointers, pointerA starting at headA and pointerB starting at headB.
-> Move both one step at a time. When a pointer reaches the end of its list, send it to the head of the other list.
-> After switching, both pointers have travelled lengthA + lengthB steps in total, so they line up at the same distance from the end.
-> If the lists intersect, the pointers meet at the intersection node.
-> If they do not intersect, both pointers become null at the same time and the loop stops, returning null.
-> This works without knowing the lengths and without extra memory.
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pointerA = headA;
    ListNode *pointerB = headB;

    while (pointerA != pointerB)
    {
        if (pointerA == nullptr)
        {
            pointerA = headB;
        }
        else
        {
            pointerA = pointerA->next;
        }

        if (pointerB == nullptr)
        {
            pointerB = headA;
        }
        else
        {
            pointerB = pointerB->next;
        }
    }

    return pointerA;
}

int main()
{
    vector<int> commonValues = {8, 4, 5};
    ListNode *common = buildList(commonValues);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr)
    {
        cout << "Intersected at the node with value " << intersection->val << "\n";
    }
    else
    {
        cout << "No intersection\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(1)
*/
