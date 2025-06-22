#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> AllPrimeFactors(int N)
{
    vector<int> result;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            if (isPrime(i))
                result.push_back(i);
            int div = N / i;
            if (div != i && isPrime(div))
                result.push_back(div);
        }
    }
    if (isPrime(N))
        result.push_back(N);
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    vector<int> primes = AllPrimeFactors(N);

    cout << "Prime factors of " << N << ": ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
