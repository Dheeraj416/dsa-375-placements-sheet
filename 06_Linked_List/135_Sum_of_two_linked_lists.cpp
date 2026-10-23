/*
QUESTION:-

Two numbers are given as linked lists, where every node holds one digit and the
most significant digit is at the head. Add the two numbers and return the sum as
a linked list in the same format (most significant digit first).

Constraints:
1 <= number of nodes in each list <= 10000
0 <= Node.val <= 9

Example 1:

Input:
first = [3,4,5]
second = [4,5]

Output:
[3,9,0]
(345 + 45 = 390)

Example 2:

Input:
first = [9,9]
second = [1]

Output:
[1,0,0]
(99 + 1 = 100)
*/

/*
APPROACH:-

-> Addition starts from the least significant digit, which is at the end of both lists. So reverse both lists first.
-> Walk through both reversed lists together, adding the two digits and the carry. The new digit is sum % 10 and the new carry is sum / 10. If one list is shorter, treat its missing digits as 0.
-> Continue until both lists end and the carry is 0 (a final carry creates one more digit).
-> Insert every new digit node at the front of the result list. The digits are produced from least to most significant, so inserting at the front gives the correct most significant first order without another reversal.
-> Let N and M be the sizes of the two lists. Reversing costs N + M and adding costs max(N, M), so the time is N + M.
-> The result list has about max(N, M) + 1 nodes, so the space is max(N, M).
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

ListNode *addLists(ListNode *first, ListNode *second)
{
    first = reverseList(first);
    second = reverseList(second);

    ListNode *result = nullptr;
    int carry = 0;

    while (first != nullptr || second != nullptr || carry != 0)
    {
        int sum = carry;

        if (first != nullptr)
        {
            sum += first->val;
            first = first->next;
        }

        if (second != nullptr)
        {
            sum += second->val;
            second = second->next;
        }

        ListNode *node = new ListNode(sum % 10);
        node->next = result;
        result = node;
        carry = sum / 10;
    }

    return result;
}

int main()
{
    vector<int> firstValues = {3, 4, 5};
    vector<int> secondValues = {4, 5};
    ListNode *first = buildList(firstValues);
    ListNode *second = buildList(secondValues);

    ListNode *result = addLists(first, second);

    printList(result);

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(max(N, M))
*/
