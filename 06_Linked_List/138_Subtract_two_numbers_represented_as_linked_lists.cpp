/*
QUESTION:-

Two non-negative numbers are given as linked lists, where every node holds one
digit and the most significant digit is at the head. The lists may have leading
zeros and different lengths. Subtract the smaller number from the larger number
and return the difference as a linked list (without leading zeros, except for
the number 0 itself).

Constraints:
1 <= number of nodes in each list <= 10000
0 <= Node.val <= 9

Example 1:

Input:
first = [1,0,0,0,0]
second = [1]

Output:
[9,9,9,9]
(10000 - 1 = 9999)

Example 2:

Input:
first = [1,0]
second = [2,5]

Output:
[1,5]
(25 - 10 = 15, the smaller number is subtracted from the larger one)
*/

/*
APPROACH:-

-> First remove the leading zeros of both lists by moving the heads forward (but keep one node, so the number 0 still has a digit).
-> Find out which number is larger. The longer list is larger. If the lengths are equal, compare the digits from the head: the first different digit decides.
-> If the first number is smaller, swap the two lists, so that we always compute larger - smaller.
-> Reverse both lists, so that the least significant digits come first. Subtract digit by digit with a borrow: diff = digit1 - borrow - digit2. If diff is negative, add 10 and set borrow = 1, otherwise set borrow = 0.
-> Insert every result digit at the front of the result list, which gives the most significant digit first order.
-> The result may have leading zeros (for example 100 - 99 = 001), so remove them at the end.
-> Let N and M be the sizes of the two lists. Every step is a single scan, so the time is N + M.
-> The result has at most max(N, M) nodes, so the space is max(N, M).
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

ListNode *removeLeadingZeros(ListNode *head)
{
    while (head != nullptr && head->next != nullptr && head->val == 0)
    {
        head = head->next;
    }
    return head;
}

int getLength(ListNode *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}

bool isSmaller(ListNode *first, ListNode *second)
{
    int firstLength = getLength(first);
    int secondLength = getLength(second);

    if (firstLength != secondLength)
    {
        return firstLength < secondLength;
    }

    while (first != nullptr)
    {
        if (first->val != second->val)
        {
            return first->val < second->val;
        }
        first = first->next;
        second = second->next;
    }

    return false;
}

ListNode *subtractLists(ListNode *first, ListNode *second)
{
    first = removeLeadingZeros(first);
    second = removeLeadingZeros(second);

    if (isSmaller(first, second))
    {
        ListNode *temp = first;
        first = second;
        second = temp;
    }

    first = reverseList(first);
    second = reverseList(second);

    ListNode *result = nullptr;
    int borrow = 0;

    while (first != nullptr)
    {
        int diff = first->val - borrow;

        if (second != nullptr)
        {
            diff -= second->val;
            second = second->next;
        }

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        ListNode *node = new ListNode(diff);
        node->next = result;
        result = node;

        first = first->next;
    }

    return removeLeadingZeros(result);
}

int main()
{
    vector<int> firstValues = {1, 0, 0, 0, 0};
    vector<int> secondValues = {1};
    ListNode *first = buildList(firstValues);
    ListNode *second = buildList(secondValues);

    ListNode *result = subtractLists(first, second);

    printList(result);

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(max(N, M))
*/
