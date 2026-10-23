/*
QUESTION:-

Design a stack that supports push(x), pop(), findMiddle() and deleteMiddle(),
all in constant time. The middle element of a stack with an even number of
elements is the lower one of the two middle elements (the one closer to the
bottom). For example in the stack [1,2,3,4] (4 is the top) the middle is 2.
pop() and findMiddle() return the value, and deleteMiddle() removes the middle
element. None of them is called on an empty stack.

Constraints:
1 <= number of operations <= 100000
1 <= x <= 100000

Example 1:

Input:
push(1), push(2), push(3), push(4), push(5), findMiddle(), deleteMiddle(),
findMiddle(), pop(), findMiddle()

Output:
3 2 5 2
(after deleteMiddle the stack is [1,2,4,5], after pop it is [1,2,4])

Example 2:

Input:
push(10), push(20), findMiddle(), pop(), findMiddle()

Output:
10 20 10
*/

/*
APPROACH:-

-> A normal array stack cannot delete from the middle in constant time. So we store the stack as a doubly linked list and keep a pointer called mid to the middle node, plus the count of elements.
-> The head of the list is the top of the stack. Every node has prev (towards the top) and next (towards the bottom).
-> The middle node is the node at position count / 2 counted from the top (the first node is position 0). This is the lower middle for an even count.
-> push: add the new node at the head. If this is the first node, mid is that node. If the old count was even, the middle moves one step towards the top, so mid = mid->prev. If the old count was odd, mid stays.
-> pop: remove the head. If the old count was odd, the middle moves one step towards the bottom, so mid = mid->next. If the old count was even, mid stays.
-> deleteMiddle: unlink the mid node. If the old count was even, the new middle is mid->prev. If the old count was odd, the new middle is mid->next.
-> findMiddle simply returns mid->val.
-> Every operation changes only a few pointers, so the time is 1 per operation.
-> Let N be the number of elements stored, the space is N.
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

struct MiddleStack
{
    DNode *head;
    DNode *mid;
    int count;

    MiddleStack()
    {
        head = nullptr;
        mid = nullptr;
        count = 0;
    }

    void push(int x)
    {
        DNode *node = new DNode(x);
        node->next = head;

        if (head != nullptr)
        {
            head->prev = node;
        }
        head = node;

        count++;

        if (count == 1)
        {
            mid = node;
        }
        else if (count % 2 == 1)
        {
            mid = mid->prev;
        }
    }

    int pop()
    {
        DNode *node = head;
        int value = node->val;

        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        if (count % 2 == 1)
        {
            mid = mid->next;
        }
        count--;

        delete node;
        return value;
    }

    int findMiddle()
    {
        return mid->val;
    }

    void deleteMiddle()
    {
        DNode *node = mid;

        if (count % 2 == 0)
        {
            mid = mid->prev;
        }
        else
        {
            mid = mid->next;
        }

        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }

        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }

        count--;
        delete node;
    }
};

int main()
{
    MiddleStack stack1;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    cout << stack1.findMiddle() << " ";
    stack1.deleteMiddle();
    cout << stack1.findMiddle() << " ";
    cout << stack1.pop() << " ";
    cout << stack1.findMiddle() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(N)
*/
