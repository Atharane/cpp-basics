#include <iostream>
using namespace std;

int toDecimal(int n, int base) {
    int result = 0;
    int basepower = 1;

    while (n > 0)
    {
        result += basepower * (n % 10);
        basepower *= base;
        n /= 10; // remove last bit
    }

    return result;
}

int fromDecimal(int n, int base) {
    int result = 0;

    while (n)
    {
        result = 10 * (n % base) + result;
        n /= base;
    }
    return result;
}

int bindec(int n)
{
    int answer = 0;
    int base = 1; // base = 2^power

    while (n > 0)
    {
        answer += base * (n % 10); // base * LSB
        base *= 2;
        n /= 10; // remove LSB
    }

    return answer;
}

int decbin(int n)
{
    int answer = 0;
    while (n)
    {
        answer = answer * 10 + n % 2;
        n /= 2;
    }
    return answer;
}

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int isPrime(int n){
    int flag = 1;
    int sqrt_n = sqrt(n);

    for(int i = 2; i <= sqrt_n; i++){
        if(n % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

void printAllPrimes(int low, int high){
    while(low <= high){
        if(isPrime(low)){
            cout << low << " ";
        }
        low++;
    }
}

int isArmstrong(int n){
    int sum = 0;
    int temp = n;

    while(temp){
        sum += pow(temp % 10, 3);
        temp /= 10;
    }

    return sum == n;
}

int hexdec(string n)
{
    int result = 0;
    int base = 1;

    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
            result += (n[i] - '0') * base;

        else if (n[i] >= 'A' && n[i] <= 'F')
            result += (n[i] - 'A' + 10) * base;

        else if (n[i] >= 'a' && n[i] <= 'f')
            result += (n[i] - 'a' + 10) * base;

        base *= 16;
    }

    return result;
}

int decoct(int n)
{
    int base = 1;
    int answer = 0;

    // get the max power of 8 <= n
    while (base <= n)
    {
        base *= 8;
    }
    base /= 8;

    // keep substracting powers of 8 from n
    while (base > 0)
    {
        int lsb = n / base;
        n = n % base;
        base /= 8;
        answer = answer * 10 + lsb;
    }

    return answer;
}

string dechex(int n)
{
    int base = 1;
    string answer = "Ath";

    // get the max power of 16 <= n
    while (base <= n)
    {
        base *= 16;
    }
    base /= 16;

    // keep substracting powers of 16 from n
    while (base > 0)
    {
        int lsb = n / base;
        n = n % base;

        if (lsb < 10)
            answer = answer + (char)(lsb + '0');
        else
            answer = answer + (char)(lsb - 10 + 'A');

        base /= 16;
    }

    return answer;
}

int binadd(int a, int b)
{
    // add two binary numbers
    int sum = 0;
    int carry = 0;
    int temp = 0;

    while (a > 0 || b > 0)
    {
        temp = carry;

        if (a % 10 == 1) // if lsb of a is 1
            temp += 1;
        if (b % 10 == 1) // if lsb of b is 1
            temp += 1;

        if (temp > 1)
            carry = 1;
        else
            carry = 0;

        sum = sum * 10 + temp % 2;

        a /= 10; // remove LSB
        b /= 10; // remove LSB
    }

    if (carry == 1)
        sum = sum * 10 + 1;

    return reverse(sum);
}

int main(int argc, char **argv)
{

    return 0;
}