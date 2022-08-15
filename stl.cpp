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

        for (auto it = numbers.begin(); it != numbers.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

        // clear all the elements in vector
        numbers.clear();

        cout << "is vector empty: " << numbers.empty() << endl;
    }


    return 0;
}