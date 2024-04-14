
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// MAX_N = 1_000_000
const int MAX_N = 1'000'000;
// const int MAX_N = 100;

template <typename T>
void my_print(const vector<T>& vec){
    // Is there a std way to print vectors? I do not know, but it should be!
    for (const T& val: vec) {
        cout << val << ", ";
    }
    cout << endl;
}

// def sieve_of_eratosthenes(limit):
vector<int> sieve_of_eratosthenes(int limit) {
    //     # Initialize a boolean array "prime[0..n]" and fill all entries it as true.
    //     # A value in prime[i] will finally be false if i is Not a prime, else true.    
    //     prime = [True for _ in range(limit + 1)]
    vector<bool> prime(limit + 1, true);  // NOTE! not the same as prime(limit + 1) {true}
    //     p = 2
    //     while p * p <= limit:
    //         # If prime[p] is not changed, then it is a prime
    //         if prime[p]:
    //             # Updating all multiples of p
    //             for i in range(p * p, limit + 1, p):
    //                 prime[i] = False
    //         p += 1
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            //# Updating all multiples of p
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    //     # Collecting all prime numbers
    vector<int> prime_numbers;
    //     prime_numbers = [p for p in range(2, limit) if prime[p]]
    for (int p = 2; p <= limit; p++) {
        if (prime[p])
            prime_numbers.push_back(p);
    }
    //     return prime_numbers
    return prime_numbers;
}


// def isCircularPrime(n):
//     # s10 = np.array(list(str(n)))
//     s0 = list(str(n))
//     a = np.array(s0)
//     n_rolls = len(s0) - 1
//     for _ in range(n_rolls):
//         a = np.roll(a, 1)
//         new_s = "".join(a)
//         new_n = int(new_s)
//         if new_n not in primes_set:
//             return False
//         # print('new_n=', new_n, ', new_s=', new_s)
//     return True

bool isCircularPrime(int n, const set<int>& primes_set) {
    string s = to_string(n);
    int n_rolls = s.length() - 1;  // 0 rolls for strings like '2', '3'
    for (int i = 0; i < n_rolls; i++) {        
        // rotate(s.begin(), s.begin() + 1, s.end());  // one way to roll by one
        s += s[0];            // Append the first character to the end
        s.erase(s.begin());  // Erase the first character
        int new_n = stoi(s);  // convert new string to int
        if (primes_set.find(new_n) == primes_set.end())
            // In C++, .end() is a member function of many container classes provided by the Standard Template Library (STL), 
            // such as std::vector, std::list, std::map, std::set, and more. 
            // It returns an iterator referring to the past-the-end element in the container.
            return false;
    }

    return true;
}

// def main():
//     res = 0
//     for n in primes:
//         if not isCircularPrime(n):
//             continue
//         res += 1
//         print('n=', n, ', res=', res)
//         # print(res)



int main(int argc, char const *argv[])
{
    cout << "Start\n";

    auto primes = sieve_of_eratosthenes(MAX_N);
    // print('primes = ', primes)
    my_print(primes);

    // primes_set = set(primes)
    set<int> primes_set;
    for (const auto& val :primes) {
        // making set. It should be a better way to convert vector to a set
        primes_set.insert(val);
    }


    int res = 0;
    for (int n : primes) {
        if (isCircularPrime(n, primes_set)) {
            res++;
            cout << "n=" << n << ", res=" << res << endl;
        }
    }

    cout << "DONE" << endl;
    cout << "Total Circular Primes: " << res << endl;

    return 0;
}


/*
n=2, res=1
n=3, res=2
n=5, res=3
n=7, res=4
n=11, res=5
n=13, res=6
n=17, res=7
n=31, res=8
n=37, res=9
n=71, res=10
n=73, res=11
n=79, res=12
n=97, res=13
n=113, res=14
n=131, res=15
n=197, res=16
n=199, res=17
n=311, res=18
n=337, res=19
n=373, res=20
n=719, res=21
n=733, res=22
n=919, res=23
n=971, res=24
n=991, res=25
n=1193, res=26
n=1931, res=27
n=3119, res=28
n=3779, res=29
n=7793, res=30
n=7937, res=31
n=9311, res=32
n=9377, res=33
n=11939, res=34
n=19391, res=35
n=19937, res=36
n=37199, res=37
n=39119, res=38
n=71993, res=39
n=91193, res=40
n=93719, res=41
n=93911, res=42
n=99371, res=43
n=193939, res=44
n=199933, res=45
n=319993, res=46
n=331999, res=47
n=391939, res=48
n=393919, res=49
n=919393, res=50
n=933199, res=51
n=939193, res=52
n=939391, res=53
n=993319, res=54
n=999331, res=55
DONE
Total Circular Primes: 55
*/
