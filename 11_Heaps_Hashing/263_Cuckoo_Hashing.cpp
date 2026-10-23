/*
QUESTION:-

Implement cuckoo hashing. It uses two hash tables, each of size 11, and two hash
functions: h1(key) = key % 11 for the first table and h2(key) = (key / 11) % 11
for the second table. A key can live only in its place in the first table or in
its place in the second table, so a search looks at only two places. To insert a
key, put it in its place in the first table. If that place is taken, the old key
there is kicked out and the new key takes its place; the kicked out key then
tries its place in the second table in the same way, and so on, going back and
forth between the tables. If this goes on for more than 22 steps there is a cycle
and a rehash is needed. Insert the given keys in order, print both tables (-1
means an empty place), and then answer the search queries.

Constraints:
1 <= number of keys <= 10
0 <= key <= 1000000

Example 1:

Input:
keys = [20,50,53,75,100,67,105,3,36,39]
search(53), search(54)

Output:
-1 100 -1 36 -1 -1 50 -1 -1 75 -1
3 20 -1 39 53 -1 67 -1 -1 105 -1
true
false

Example 2:

Input:
keys = [1,12,23]
search(12), search(13)

Output:
-1 23 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 12 -1 -1 -1 -1 -1 -1 -1 -1 -1
true
false
*/

/*
APPROACH:-

-> Keep two arrays table[0] and table[1] of size 11, filled with -1 (empty). The function getHash(tableId, key) returns key % 11 for table 0 and (key / 11) % 11 for table 1.
-> Insert a key: set current = key and tableId = 0. Repeat at most 22 times: compute the place with getHash(tableId, current). If that place is empty, store current there and finish.
-> If the place is taken, swap current with the key stored there (the new key moves in, the old key is kicked out), and switch to the other table: tableId = 1 - tableId. Continue with the kicked out key.
-> If the loop ends without finding an empty place, there is a cycle, so report that a rehash is needed.
-> Search a key: it can only be at table[0][h1(key)] or at table[1][h2(key)], so check these two places only.
-> Search takes constant time in the worst case. An insert takes constant time on average, as long as the tables are not too full.
-> The two tables take space for 2 * 11 keys; in general, with S the size of one table, the space is S.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

const int TABLE_SIZE = 11;
const int EMPTY = -1;

int getHash(int tableId, int key)
{
    if (tableId == 0)
    {
        return key % TABLE_SIZE;
    }
    return (key / TABLE_SIZE) % TABLE_SIZE;
}

bool insertKey(vector<vector<int>> &table, int key)
{
    int current = key;
    int tableId = 0;

    for (int step = 0; step < 2 * TABLE_SIZE; step++)
    {
        int position = getHash(tableId, current);

        if (table[tableId][position] == EMPTY)
        {
            table[tableId][position] = current;
            return true;
        }

        swap(current, table[tableId][position]);
        tableId = 1 - tableId;
    }

    return false;
}

bool searchKey(vector<vector<int>> &table, int key)
{
    if (table[0][getHash(0, key)] == key)
    {
        return true;
    }

    if (table[1][getHash(1, key)] == key)
    {
        return true;
    }

    return false;
}

void printBool(bool value)
{
    if (value)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}

int main()
{
    vector<int> keys = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
    vector<vector<int>> table(2, vector<int>(TABLE_SIZE, EMPTY));

    for (int i = 0; i < (int)keys.size(); i++)
    {
        if (!insertKey(table, keys[i]))
        {
            cout << "Cycle found while inserting " << keys[i] << ", rehash is needed\n";
        }
    }

    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << table[t][i] << " ";
        }
        cout << "\n";
    }

    printBool(searchKey(table, 53));
    printBool(searchKey(table, 54));

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(S)
*/
