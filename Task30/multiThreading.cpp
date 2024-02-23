#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
using ull = unsigned long long;
mutex mx;

ull factorialCalc(int n)
{
    ull result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void fibanociiCalc(int n, ull *fib)
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void factorial(int n)
{
    lock_guard<mutex> lock(mx);
    cout << "Factorial of " << n << ": " << factorialCalc(n) << endl;
}

void fibanocii(int n)
{
    ull seq[n];
    fibanociiCalc(n, seq);
    lock_guard<mutex> lock(mx);
    cout << "Fibonacci sequence up to " << n << " terms: ";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    thread fact_Thread(factorial, number);
    thread fibanocii_Thread(fibanocii, number);

    fact_Thread.join();
    fibanocii_Thread.join();
    return 0;
}
