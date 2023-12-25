// Primes sum 
/*

Given a number N. Find if it can be expressed as sum of two prime numbers.

Example 1:

Input: N = 34
Output: "Yes" 
Explanation: 34 can be expressed as 
sum of two prime numbers.



Algorithm:

1. Start a loop from i = 2 up to n - 1.
2. Inside the loop, check if both i and n - i are prime using the isprime method.
If yes, return "Yes" as n can be expressed as the sum of two prime numbers.
3. If the loop completes without finding a pair of prime numbers, return "No."
*/
//solution

class Solution {
public:
    bool isprime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

    string isSumOfTwo(int n){
        for(int i=2;i<n-1;i++)
        {
            if(isprime(i) && isprime(n-i))
                return "Yes";
        }
        return "No";
    }
};