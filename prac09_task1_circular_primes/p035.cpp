#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 1000000;
// MAX_N = 100
template <typename T>
void print(const vector<T> &vec)
{
    for (auto &element : vec)
    {
        cout << element << " ";
    }
    cout << endl;
}

vector<int> sieve_of_eratosthenes(int limit)
{
    // Initialize a boolean array "prime[0..n]" and fill all entries it as true.
    // A value in prime[i] will finally be false if i is Not a prime, else true.
    vector<bool> prime(limit, true);
    for (int p = 2; p * p <= limit; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Updating all multiples of p
            for (int i = p * p; i < (limit + 1); i = i + p)
            {
                prime[i] = false;
            }
        }
    }
    // Collecting all prime numbers
    vector<int> prime_numbers;
    for (int p = 2; p < limit; p++)
    {
        if (prime[p])
            prime_numbers.push_back(p);
    }
    return prime_numbers;
}

bool isCircularPrime(int n, const set<int> &primes_set)
{
    string s = to_string(n);
    int n_rolls = s.length() - 1;

    for (int i = 0; i < n_rolls; i++)
    {
        s += s[0];           // Append the first character to the end
        s.erase(s.begin());  // Erase the first character
        int new_n = stoi(s); // convert new string to int
        if (primes_set.find(new_n) == primes_set.end())
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    auto primes = sieve_of_eratosthenes(MAX_N);
    // print('primes = ', primes)
    print(primes); // print all elements of primes

    // primes_set = set(primes)
    set<int> primes_set;
    for (const auto &val : primes)
    {
        primes_set.insert(val);
    }

    int res = 0;
    for (int n : primes)
    {
        if (isCircularPrime(n, primes_set))
        {
            res++;
            cout << "n=" << n << ", res=" << res << endl;
        }
    }

    cout << "DONE" << endl;
    cout << "Total Circular Primes: " << res << endl;

    return 0;
}