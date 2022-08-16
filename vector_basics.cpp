#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> numbers;

    numbers.push_back(1); // {1}
    numbers.push_back(2); // {1, 2}
    numbers.push_back(3); // {1, 2, 3}
    numbers.push_back(4); // {1, 2, 3, 4}
    numbers.push_back(5); // {1, 2, 3, 4, 5}

    cout << "Size of vector: " << numbers.size() << endl; // 5

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " "; 

    cout << endl;

    cout << "last element: " << numbers.back() << endl; // 5

    // removes last element
    numbers.pop_back();

    // for each loop
    for (auto it : numbers)
        cout << it << " ";

    cout << endl;

    // clear all the elements in vector
    numbers.clear();

    cout << "is vector empty: " << numbers.empty() << endl;

    // vector of predefined size & default value
    vector<int> numbers2(5, -1);

    // copy a vector
    vector<int> numbers3(numbers2);

    return 0;
}