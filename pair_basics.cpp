#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, string> myPair(1, "lorem");

    cout << "first element: " << myPair.first << endl;
    cout << "second element: " << myPair.second << endl;

    // Nested pair
    pair<int, pair<string, string>> myPair2(9, make_pair("karim", "benzema"));

    cout << "first element: " << myPair2.first << endl;
    cout << "second.first element: " << myPair2.second.first << endl;
    cout << "second.second element: " << myPair2.second.second << endl;

    // Array of pairs
    pair<int, string> pairArr[3] = {make_pair(1, "david"), make_pair(8, "bruno"), make_pair(25, "jadon")};
    cout << "third element of array: " << pairArr[2].second << endl;

    return 0;
}