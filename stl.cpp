#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Unordered Set
    /*
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
        cout << "New set size: " << language.size() <<endl;

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
    }
    */

    // Sets
    /*
    {
        set<char> alphabets;

        alphabets.insert('a');
        alphabets.insert('b');
        alphabets.insert('c');
        alphabets.insert('d');
        alphabets.insert('e');

        cout << "Size of set: " << alphabets.size() << endl;
        for(auto it = alphabets.begin(); it != alphabets.end(); it++)
        {
            cout << *it << " ";
        }
    }  
    */  

    // Vector

    {
        vector<int> numbers;

        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        cout << "Size of vector: " << numbers.size() << endl;

        for(auto it = numbers.begin(); it != numbers.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        cout<<"last element: "<<numbers.back()<<endl;

        // removes last element
        numbers.pop_back();
        // for each loop
        for (auto it : numbers)
        {
            cout << it << " ";
        }
        cout << endl;

        // clear all the elements in vector
        numbers.clear();

        cout << "is vector empty: " << numbers.empty() << endl;

        // vector of predefined size & default value
        vector<int> numbers2(5, 0);

        // copy a vector
        vector<int> numbers3(numbers2);

        for (auto it = numbers3.begin(); it != numbers3.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }


    // Pair
    /*
    {
        pair<int, string> myPair(1, "lorem");

        cout << "first element: " << myPair.first << endl;
        cout << "second element: " << myPair.second << endl;

        // Nested pair
        pair<int, pair<string, string>> myPair2(9, make_pair("karim", "benzema"));

        cout<<"first element: "<<myPair2.first<<endl;
        cout<<"second element: "<<myPair2.second.first<<endl;
        cout<<"third element: "<<myPair2.second.second<<endl;

        // Array of pairs
        pair<int, string> pairArr[3] = {make_pair(1, "david"), make_pair(8, "bruno"), make_pair(25, "jadon")};
        cout<<"third element of array: "<<pairArr[2].second<<endl;
    }
    */
    


    return 0;
}