#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Sets

    set<char> alphabets;

    alphabets.insert('a');
    alphabets.insert('b');
    alphabets.insert('c');
    alphabets.insert('d');
    alphabets.insert('e');

    cout << "Size of set: " << alphabets.size() << endl;
    for (auto it = alphabets.begin(); it != alphabets.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}