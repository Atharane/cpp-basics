#include <iostream>
#include <math.h>
using namespace std;

void primeSieve(int n)
{
    int composites[n + 1] = {0};
    // composites[i] is 0 if i is prime

    for (int i = 2; i*i <= n; i++)
    {
        if (composites[i])
            continue;

        int toMark = i * i;

        while (toMark <= n)
        {
            composites[toMark] = 1;
            toMark += i;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (!composites[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void primeFactorize(int n)
{
    int composites[n + 1];


    // consider each number to be smallest divisor of itself
    for (int i = 2; i <= n; i++)
    {
        composites[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        // already modified
        if (composites[i] != i)
            continue;

        int toMark = i * i;

        while (toMark <= n)
        {
            // not already marked
            if (composites[toMark] == toMark)
                composites[toMark] = i;

            toMark += i;
        }
    }

    while (n != 1)
    {
        int smallestDivisor = composites[n];
        cout << smallestDivisor << " ";
        n /= smallestDivisor;
    }
    cout << endl;
}

int main()
{
    cout << "N: ";
    int n;
    cin >> n;

    // primeSieve(n);

    primeFactorize(n);

    return 0;
}