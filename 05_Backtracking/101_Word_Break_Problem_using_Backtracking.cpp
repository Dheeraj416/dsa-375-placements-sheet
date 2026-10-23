/*
QUESTION:-

Given a string s and a dictionary of words, add spaces in s to construct
sentences in which every word is a valid dictionary word. Return all such
possible sentences in any order. A dictionary word may be used more than once.

Constraints:
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of lowercase English letters.

Example 1:

Input:
s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]

Output:
["cat sand dog","cats and dog"]

Example 2:

Input:
s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]

Output:
["pine apple pen apple","pine applepen apple","pineapple pen apple"]
*/

/*
APPROACH:-

-> Put the dictionary words in an unordered_set so that a word can be looked up in O(1) on average.
-> Use recursion with a start index that marks the beginning of the remaining text.
-> If start reaches the end of the text, join the words chosen so far with spaces and store the sentence.
-> Otherwise try every end position. If the substring from start to end is a dictionary word, add it and recurse from end.
-> After the recursive call remove the word (backtrack) and try a longer substring.
-> In the worst case (for example "aaaa" with the word "a") there are 2^(N - 1) ways to split the string.
-> Each sentence takes up to N steps to build, which gives the stated time complexity.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void breakWords(string &text, int start, unordered_set<string> &dictionary, vector<string> &current, vector<string> &answer)
{
    if (start == (int)text.size())
    {
        string sentence = "";

        for (int i = 0; i < (int)current.size(); i++)
        {
            if (i > 0)
            {
                sentence = sentence + " ";
            }

            sentence = sentence + current[i];
        }

        answer.push_back(sentence);
        return;
    }

    for (int end = start + 1; end <= (int)text.size(); end++)
    {
        string word = text.substr(start, end - start);

        if (dictionary.find(word) != dictionary.end())
        {
            current.push_back(word);
            breakWords(text, end, dictionary, current, answer);
            current.pop_back();
        }
    }
}

vector<string> wordBreak(string &text, vector<string> &words)
{
    unordered_set<string> dictionary(words.begin(), words.end());
    vector<string> answer;
    vector<string> current;

    breakWords(text, 0, dictionary, current, answer);

    return answer;
}

int main()
{
    string text = "catsanddog";
    vector<string> words = {"cat", "cats", "and", "sand", "dog"};

    vector<string> answer = wordBreak(text, words);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(2^N * N)
SPACE COMPLEXITY = O(N)
*/
