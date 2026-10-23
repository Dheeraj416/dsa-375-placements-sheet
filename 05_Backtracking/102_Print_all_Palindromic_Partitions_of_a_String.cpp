/*
QUESTION:-

Given a string s, partition s such that every substring of the partition is a
palindrome. Return all the possible palindrome partitionings of s.

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.

Example 1:

Input:
s = "aab"

Output:
[["a","a","b"],["aa","b"]]

Example 2:

Input:
s = "a"

Output:
[["a"]]
*/

/*
APPROACH:-

-> Use recursion with a start index. The function decides where the next piece of the partition ends.
-> If start reaches the end of the string, the current list of pieces is a complete valid partition, so store it.
-> Otherwise try every end index from start to the last character.
-> If the substring from start to end is a palindrome, add it to the current list and recurse from end + 1.
-> After the recursive call, remove the last piece (backtrack) and try the next end index.
-> A palindrome check compares characters from both ends moving inward and costs O(N).
-> A string of length N can be cut in 2^(N - 1) ways, which gives the time complexity.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &text, int low, int high)
{
    while (low < high)
    {
        if (text[low] != text[high])
        {
            return false;
        }

        low++;
        high--;
    }

    return true;
}

void partitionText(string &text, int start, vector<string> &current, vector<vector<string>> &answer)
{
    if (start == (int)text.size())
    {
        answer.push_back(current);
        return;
    }

    for (int end = start; end < (int)text.size(); end++)
    {
        if (isPalindrome(text, start, end))
        {
            current.push_back(text.substr(start, end - start + 1));
            partitionText(text, end + 1, current, answer);
            current.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string &text)
{
    vector<vector<string>> answer;
    vector<string> current;

    partitionText(text, 0, current, answer);

    return answer;
}

int main()
{
    string text = "aab";

    vector<vector<string>> answer = palindromePartition(text);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            if (j > 0)
            {
                cout << ",";
            }
            cout << "\"" << answer[i][j] << "\"";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^N * N)
SPACE COMPLEXITY = O(N)
*/
