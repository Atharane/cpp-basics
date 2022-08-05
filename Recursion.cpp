/*
Reference:
https://www.youtube.com/watch?v=7F3MYyw3Jmg&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=39
https://www.youtube.com/watch?v=oSQbwlepoCU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=38
https://www.youtube.com/watch?v=j9RG18jfnRY&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=40
https://www.youtube.com/watch?v=9rt-hFcXd0M&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=41
*/

#include <iostream>
using namespace std;

int fibonacci(int a)
{
    if (a <= 1)
        return 0;
    if (a == 2)
        return 1;

    return fibonacci(a - 1) + fibonacci(a - 2);
}

int factorial(int a)
{
    if (a <= 1)
        return 1;
    return a * factorial(a - 1);
}

bool isSorted(int *array, size_t size)
{
    if (size == 1)
        return true;

    return array[0] <= array[1] && isSorted(array + 1, size - 1);
}

int firstOccurance(int *arr, size_t size, int target)
{
    if (size == 0)
        return -1;

    // return as soon as target is found, no need to make any further calls
    if (arr[0] == target)
        return 0; // index relative to the subarray arr

    int occurance = firstOccurance(arr + 1, size - 1, target);

    if (occurance != -1)
        return occurance + 1; // index relative to the subarray arr, thus +1

    return -1;
}

int lastOccurance(int *arr, size_t size, int target)
{
    if (size == 0)
        return -1;

    // make further calls till the end of the array
    int occurance = lastOccurance(arr + 1, size - 1, target);

    // target encountered to the right of the current index
    if (occurance != -1)
        return occurance + 1; // index relative to the subarray arr, thus +1

    // check self for target
    if (arr[0] == target)
        return 0; // index relative to the subarray arr

    return -1; // self is not target
}

string moveCharToEnd(string s, char target)
{
    if (s.length() == 1)
        return s;

    char firstChar = s[0];
    string returnString = moveCharToEnd(s.substr(1), target);

    if (firstChar == target)
        return returnString + firstChar;
    else
        return firstChar + returnString;
}

void hanoi(int disks, string from, string helper, string to)
{
    if (disks)
    {
        hanoi(disks - 1, from, to, helper);
        cout << "Move disk from " << from << " to " << to << endl;
        hanoi(disks - 1, helper, from, to);
    }
}

int main()
{
    /*
    cout << fibonacci(8) << endl;
    cout << factorial(12) << endl;
    */

    /*
    int array[] = {1, 1, 2, 3, 5, 18, 13, 21, 34, 55, 89};
    size_t size = sizeof(array) / sizeof(array[0]);
    cout << isSorted(array, size) << endl;
    */

    /*
    int array[] = {8, 0, 2, 2, 7, 8, 7, 3, 2, 1, 6, 8, 2, 0, 8};
    size_t size = sizeof(array) / sizeof(array[0]);
    cout << firstOccurance(array, size, 2) << endl;
    cout << lastOccurance(array, size, 2) << endl;
    */

    // cout << moveCharToEnd("atharva", 'a') << endl;

    // hanoi(4, "A", "B", "C");

    return 0;
}