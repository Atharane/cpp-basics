#include <bits/stdc++.h>
using namespace std;

int main()
{

    unordered_set<string> language;

    language.insert("lorem");
    language.insert("ipsum");
    language.insert("amet");

    cout << language.count("dolor") << endl;

    if (language.find("ipsum") != language.end())
        cout << *(language.find("ipsum")) << " found!" << endl;
    else
        cout << "Element not found!";

    language.erase("lorem");
    language.erase(language.begin());
    cout << "New set size: " << language.size() << endl;

    for (auto it = language.begin(); it != language.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // deletes all the elements in unordered set
    language.erase(language.begin(), language.end());

    cout << "is unordered set empty: " << language.empty() << endl;

    // deletes all the elements in unordered set
    language.clear();

    return 0;
}