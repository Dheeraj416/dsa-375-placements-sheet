/*
QUESTION:-

Given a fraction as a numerator and a denominator, write it as a decimal number.
If the decimal part repeats forever, find the repeating (recurring) part and
write it inside brackets. For example 1/3 = 0.333... is written as 0.(3).

Constraints:
1 <= numerator, denominator <= 100000

Example 1:

Input:
numerator = 22, denominator = 7

Output:
3.(142857)

Example 2:

Input:
numerator = 1, denominator = 6

Output:
0.1(6)
*/

/*
APPROACH:-

-> Do the long division by hand. The integer part is numerator / denominator, and the first remainder is numerator % denominator. If the remainder is 0, the answer is just the integer part.
-> For the decimal part, repeat: multiply the remainder by 10, the next digit is remainder / denominator, and the new remainder is remainder % denominator. Stop when the remainder becomes 0 (the decimal ends).
-> The digits repeat as soon as a remainder appears for the second time, because the same remainder always gives the same following digits.
-> Keep a hash map from each remainder to the position in the result string where its digit will be written. Before computing a digit, check if the current remainder is already in the map. If yes, the repeating part starts at the stored position: insert "(" there and add ")" at the end.
-> There are at most denominator different remainders, so the loop ends after at most that many steps.
-> Let D be the denominator. The time is D, because each remainder is seen at most once.
-> The map stores up to D remainders, so the space is D.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    string result = to_string(numerator / denominator);
    int remainder = numerator % denominator;

    if (remainder == 0)
    {
        return result;
    }

    result += ".";
    unordered_map<int, int> seen;

    while (remainder != 0)
    {
        if (seen.count(remainder) > 0)
        {
            result.insert(seen[remainder], "(");
            result += ")";
            break;
        }

        seen[remainder] = result.size();

        remainder = remainder * 10;
        result += to_string(remainder / denominator);
        remainder = remainder % denominator;
    }

    return result;
}

int main()
{
    int numerator = 22;
    int denominator = 7;

    cout << fractionToDecimal(numerator, denominator) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(D)
SPACE COMPLEXITY = O(D)
*/
