/*
QUESTION:-

Given the head of a singly linked list, reverse the list and return the new
head.

Constraints:
0 <= number of nodes <= 5000
-5000 <= Node.val <= 5000

Example 1:

Input:
head = [1,2,3,4,5]

Output:
[5,4,3,2,1]

Example 2:

Input:
head = [1,2]

Output:
[2,1]
*/

/*
APPROACH:-

-> Use three pointers: previous, current and nextNode.
-> Start with previous = null and current = head.
-> At each step save current->next in nextNode, because the link is about to be changed.
-> Point current->next to previous, which reverses one link.
-> Move previous to current and current to nextNode.
-> When current becomes null, previous is the head of the reversed list.
-> Only the links are changed, so no new nodes are created.
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

ListNode *reverseList(ListNode *head)
{
    ListNode *previous = nullptr;
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);

    ListNode *reversed = reverseList(head);

    printList(reversed);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
