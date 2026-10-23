/*
QUESTION:-

Given a string s and a list of queries, where every query is a pair (L, R),
tell for every query whether the substring s[L..R] (both ends included, 0
indexed) is a palindrome. Print "yes" or "no" for every query, each on its own
line.

Constraints:
1 <= length of s <= 2000
1 <= number of queries <= 100000
0 <= L <= R < length of s

Example 1:

Input:
s = "abaaabaaaba"
queries = (0,10), (5,8), (2,5), (5,9)

Output:
yes
no
no
yes

Example 2:

Input:
s = "abcba"
queries = (0,4), (1,3), (0,2)

Output:
yes
yes
no
*/

/*
APPROACH:-

-> Doing a palindrome check for every query would be slow if there are many queries. Instead, find the answer for all substrings once, and answer every query by a table look up.
-> Let isPal[i][j] be true when s[i..j] is a palindrome. A substring of length 1 is a palindrome. A substring is a palindrome when its first and last characters are equal and the inside part s[i+1..j-1] is a palindrome (or is empty).
-> Fill the table by increasing length: for length 1 set true; for length 2 check s[i] == s[i+1]; for longer lengths use s[i] == s[j] && isPal[i+1][j-1].
-> Then every query (L, R) is answered with isPal[L][R] in constant time.
-> Let N be the length of the string and Q the number of queries. Filling the table costs N * N and the queries cost Q, so the time is N * N + Q.
-> The table has N * N cells, so the space is N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> buildTable(string &s)
{
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        isPal[i][i] = true;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i + length - 1 < n; i++)
        {
            int j = i + length - 1;

            if (s[i] == s[j])
            {
                if (length == 2)
                {
                    isPal[i][j] = true;
                }
                else
                {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }
    }

    return isPal;
}

int main()
{
    string s = "abaaabaaaba";
    vector<vector<int>> queries = {{0, 10}, {5, 8}, {2, 5}, {5, 9}};

    vector<vector<bool>> isPal = buildTable(s);

    for (int i = 0; i < (int)queries.size(); i++)
    {
        if (isPal[queries[i][0]][queries[i][1]])
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * N + Q)
SPACE COMPLEXITY = O(N * N)
*/
