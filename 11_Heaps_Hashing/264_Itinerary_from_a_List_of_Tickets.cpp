/*
QUESTION:-

You are given a list of tickets, each one is a pair (from, to) of cities. All the
tickets together make one trip: the destination of one ticket is the starting
city of the next ticket, and no city is visited twice. Print the itinerary in
order, one leg per line, in the form "from->to".

Constraints:
1 <= number of tickets <= 100000
Every city name is a string without spaces. The tickets form a single path.

Example 1:

Input:
tickets = [(Chennai, Banglore), (Bombay, Delhi), (Goa, Chennai), (Delhi, Goa)]

Output:
Bombay->Delhi
Delhi->Goa
Goa->Chennai
Chennai->Banglore

Example 2:

Input:
tickets = [(A, B), (B, C)]

Output:
A->B
B->C
*/

/*
APPROACH:-

-> Store the tickets in a hash map nextCity, which maps every from city to its to city. Also store all the destinations in a set.
-> The starting city of the whole trip is the only city that appears as a source but never as a destination. Find it by checking every key of the map against the set of destinations.
-> From the start city, repeat: print "city->nextCity[city]", and move to the next city. Stop when the current city has no ticket going out of it.
-> Let N be the number of tickets. Building the map and the set costs N, finding the start costs N and following the trip costs N, so the time is N (we use an ordered map here, so it is really N * log N).
-> The map and the set take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void printItinerary(vector<pair<string, string>> &tickets)
{
    map<string, string> nextCity;
    set<string> destinations;

    for (int i = 0; i < (int)tickets.size(); i++)
    {
        nextCity[tickets[i].first] = tickets[i].second;
        destinations.insert(tickets[i].second);
    }

    string start = "";
    for (map<string, string>::iterator it = nextCity.begin(); it != nextCity.end(); it++)
    {
        if (destinations.count(it->first) == 0)
        {
            start = it->first;
            break;
        }
    }

    while (nextCity.count(start) > 0)
    {
        cout << start << "->" << nextCity[start] << "\n";
        start = nextCity[start];
    }
}

int main()
{
    vector<pair<string, string>> tickets;
    tickets.push_back({"Chennai", "Banglore"});
    tickets.push_back({"Bombay", "Delhi"});
    tickets.push_back({"Goa", "Chennai"});
    tickets.push_back({"Delhi", "Goa"});

    printItinerary(tickets);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
