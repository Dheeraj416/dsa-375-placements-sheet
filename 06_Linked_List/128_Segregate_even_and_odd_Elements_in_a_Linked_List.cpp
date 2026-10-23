/*
QUESTION:-

Given the head of a singly linked list of integers, rearrange it so that all the
even values come before all the odd values. The relative order of the even
nodes and the relative order of the odd nodes must stay the same as in the
original list.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
head = [17,15,8,12,10,5,4,1,7,6]

Output:
[8,12,10,4,6,17,15,5,1,7]

Example 2:

Input:
head = [1,3,5]

Output:
[1,3,5]
*/

/*
APPROACH:-

-> Build two separate lists while walking through the original list: one for even values and one for odd values.
-> Use a dummy node as the start of each new list, so that adding the first node is not a special case.
-> For every node, cut its next pointer and append it to the tail of the even list or the odd list, depending on its value.
-> Appending at the tail keeps the original relative order inside each list.
-> At the end connect the tail of the even list to the first node of the odd list, and return the first even node.
-> Let N be the number of nodes. Every node is moved once, so the time is N.
-> Only the existing nodes are relinked, so the space is constant.
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

ListNode *segregateEvenOdd(ListNode *head)
{
    ListNode *evenDummy = new ListNode(0);
    ListNode *oddDummy = new ListNode(0);
    ListNode *evenTail = evenDummy;
    ListNode *oddTail = oddDummy;

    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        current->next = nullptr;

        if (current->val % 2 == 0)
        {
            evenTail->next = current;
            evenTail = current;
        }
        else
        {
            oddTail->next = current;
            oddTail = current;
        }

        current = nextNode;
    }

    evenTail->next = oddDummy->next;
    ListNode *result = evenDummy->next;

    delete evenDummy;
    delete oddDummy;
    return result;
}

int main()
{
    vector<int> values = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    ListNode *head = buildList(values);

    head = segregateEvenOdd(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
