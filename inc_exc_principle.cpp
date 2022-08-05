#include <iostream>
#include <math.h>
using namespace std;

int divisible(int a, int b, int n)
{
    int numDivisibleByA = n / a;
    int numDivisibleByB = n / b;
    int numDivisibleByBoth = n / (a * b);

    return numDivisibleByA + numDivisibleByB - numDivisibleByBoth;
}

// find gcd of two numbers
int euclid(int a, int b)
{
    /*
    if (b == 0)
        return a;
    return euclid(b, a % b);
    */

    // iterative version
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    cout << "Input: ";
    int a, b, n;

    cin >> a >> b >> n;
    cout << divisible(a, b, n) << endl;

    cin >> a >> b;
    cout << euclid(a, b) << endl;

    return 0;
}