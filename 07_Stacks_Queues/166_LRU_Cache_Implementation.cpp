/*
QUESTION:-

Design a data structure that follows the Least Recently Used (LRU) cache
policy. Implement the class LRUCache with a capacity, get(key) which returns the
value of the key if it exists, otherwise -1, and put(key, value) which inserts
or updates the key. When the number of keys exceeds the capacity, the least
recently used key must be removed. Using a key (get or put) makes it the most
recently used. Both get and put must run in O(1) average time.

Constraints:
1 <= capacity <= 3000
0 <= key, value <= 100000

Example 1:

Input:
capacity = 2, then: put(1,1), put(2,2), get(1), put(3,3), get(2), put(4,4), get(1), get(3), get(4)

Output:
1 -1 -1 3 4

Example 2:

Input:
capacity = 1, then: put(1,10), put(2,20), get(1), get(2)

Output:
-1 20
*/

/*
APPROACH:-

-> Combine two structures: a doubly linked list (std::list) that keeps the keys ordered from most recently used at the front to least recently used at the back, and a hash map from key to the position of its node in the list.
-> get: if the key is missing return -1. Otherwise remove its node, insert it again at the front (it is now the most recently used), update the map and return the value.
-> put: if the key already exists, remove its old node. Else if the cache is full, remove the node at the back (the least recently used key) and erase it from the map.
-> Then insert the new pair at the front and store its position in the map.
-> The hash map gives O(1) lookup and the linked list gives O(1) removal and insertion when the position is known.
-> The two structures together hold at most capacity entries.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> position;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if (position.find(key) == position.end())
        {
            return -1;
        }

        list<pair<int, int>>::iterator it = position[key];
        int value = it->second;

        items.erase(it);
        items.push_front({key, value});
        position[key] = items.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (position.find(key) != position.end())
        {
            items.erase(position[key]);
        }
        else if ((int)items.size() == capacity)
        {
            int leastUsedKey = items.back().first;
            items.pop_back();
            position.erase(leastUsedKey);
        }

        items.push_front({key, value});
        position[key] = items.begin();
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";
    cache.put(3, 3);
    cout << cache.get(2) << "\n";
    cache.put(4, 4);
    cout << cache.get(1) << "\n";
    cout << cache.get(3) << "\n";
    cout << cache.get(4) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(CAPACITY)
*/
