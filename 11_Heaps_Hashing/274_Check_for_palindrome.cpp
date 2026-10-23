/*
QUESTION:-

A phrase is a palindrome if, after converting all uppercase letters to lowercase
and removing all characters that are not letters or digits, it reads the same
forwards and backwards. Given a string s, return true if it is a palindrome,
otherwise return false.

Constraints:
1 <= s.length <= 200000
s contains printable ASCII characters.

Example 1:

Input:
s = "A man, a plan, a canal: Panama"

Output:
true
(it becomes "amanaplanacanalpanama")

Example 2:

Input:
s = "race a car"

Output:
false
(it becomes "raceacar")
*/

/*
APPROACH:-

-> Use two pointers, left at the start and right at the end of the string.
-> Move left forward until it points to a letter or a digit, and move right backward until it points to a letter or a digit. This skips spaces and punctuation without building a new string.
-> Compare the two characters after converting both to lowercase. If they are different, the string is not a palindrome, so return false.
-> If they are equal, move both pointers inwards and repeat until they meet.
-> Edge case: a string with no letters or digits becomes empty, and an empty string is a palindrome, so the answer is true.
-> Let N be the length of the string. Each pointer moves over the string once, so the time is N.
-> Only two index variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = (int)s.size() - 1;

    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    bool answer = isPalindrome(s);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
