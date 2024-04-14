from pprint import pprint

import numpy as np
from tqdm import tqdm

MAX_N = 1_000_000
# MAX_N = 100


def sieve_of_eratosthenes(limit):
    # Initialize a boolean array "prime[0..n]" and fill all entries it as true.
    # A value in prime[i] will finally be false if i is Not a prime, else true.
    prime = [True for _ in range(limit + 1)]
    p = 2
    while p * p <= limit:
        # If prime[p] is not changed, then it is a prime
        if prime[p]:
            # Updating all multiples of p
            for i in range(p * p, limit + 1, p):
                prime[i] = False
        p += 1

    # Collecting all prime numbers
    prime_numbers = [p for p in range(2, limit) if prime[p]]
    return prime_numbers


primes = sieve_of_eratosthenes(MAX_N)
primes_set = set(primes)
# print('primes = ', primes)


def isCircularPrime(n):
    s0 = list(str(n))
    a = np.array(s0)
    n_rolls = len(s0) - 1
    for _ in range(n_rolls):
        # without numpy, use list. 
        # Then pop front and append to the back to get the roll by one
        a = np.roll(a, 1)
        new_s = "".join(a)
        new_n = int(new_s)
        if new_n not in primes_set:
            return False
        # print('new_n=', new_n, ', new_s=', new_s)

    return True


def main():
    res = 0
    for n in primes:
        if not isCircularPrime(n):
            continue
        res += 1
        print('n=', n, ', res=', res)



if __name__ == "__main__":
    main()

print("DONE")
# n= 2 , res= 1
# n= 3 , res= 2
# n= 5 , res= 3
# n= 7 , res= 4
# n= 11 , res= 5
# n= 13 , res= 6
# n= 17 , res= 7
# n= 31 , res= 8
# n= 37 , res= 9
# n= 71 , res= 10
# n= 73 , res= 11
# n= 79 , res= 12
# n= 97 , res= 13
# n= 113 , res= 14
# n= 131 , res= 15
# n= 197 , res= 16
# n= 199 , res= 17
# n= 311 , res= 18
# n= 337 , res= 19
# n= 373 , res= 20
# n= 719 , res= 21
# n= 733 , res= 22
# n= 919 , res= 23
# n= 971 , res= 24
# n= 991 , res= 25
# n= 1193 , res= 26
# n= 1931 , res= 27
# n= 3119 , res= 28
# n= 3779 , res= 29
# n= 7793 , res= 30
# n= 7937 , res= 31
# n= 9311 , res= 32
# n= 9377 , res= 33
# n= 11939 , res= 34
# n= 19391 , res= 35
# n= 19937 , res= 36
# n= 37199 , res= 37
# n= 39119 , res= 38
# n= 71993 , res= 39
# n= 91193 , res= 40
# n= 93719 , res= 41
# n= 93911 , res= 42
# n= 99371 , res= 43
# n= 193939 , res= 44
# n= 199933 , res= 45
# n= 319993 , res= 46
# n= 331999 , res= 47
# n= 391939 , res= 48
# n= 393919 , res= 49
# n= 919393 , res= 50
# n= 933199 , res= 51
# n= 939193 , res= 52
# n= 939391 , res= 53
# n= 993319 , res= 54
# n= 999331 , res= 55
# DONE
#
# Process finished with exit code 0
