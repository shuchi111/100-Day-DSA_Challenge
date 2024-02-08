'''
Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.




The code implements the Sieve of Eratosthenes algorithm to count the number of prime numbers up to a given limit n. It initializes a boolean list marking all numbers as potential primes, iteratively marks the multiples of primes as non-prime, and returns the count of remaining primes. The approach efficiently sieves out non-prime numbers, achieving a time complexity close to O(n log log n).


Algorithm Overview:

Check for the base case: If n is less than or equal to 2, return 0 since there are no primes in this range.
Initialize a boolean list primes with True for all numbers from 0 to n-1.
Mark 0 and 1 as non-prime (set them to False).
Iterate through numbers from 2 to the square root of n.
If the current number i is marked as prime in the primes list:
Mark its multiples as non-prime by setting corresponding elements to False using list slicing.
The count of True values in the primes list represents the number of primes up to n.
Return the count.

'''

class Solution:
    def countPrimes(self, n: int) -> int:
        # Check for base case where n is less than or equal to 2
        if n <= 2:
            return 0

        # Initialize a boolean list 'primes' to True for all numbers from 0 to n-1
        primes = [True] * n
        primes[0] = primes[1] = False  # 0 and 1 are not prime numbers

        # Iterate through numbers from 2 to the square root of n
        for i in range(2, int(n**0.5) + 1):
            # If i is a prime number, mark its multiples as non-prime
            if primes[i]:
                primes[i*i:n:i] = [False] * ((n-1-i*i)//i + 1)

        # Return the count of True values in the 'primes' list, indicating the number of primes up to n
        return sum(primes)
