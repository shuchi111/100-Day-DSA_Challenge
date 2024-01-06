//GFG POTD - Techfest and the Queue


/*
Input: 
a = 9
b = 12
Output: 
8
Explanation: 
For 9, prime factorization is:32 
So, sum of the powers of primes is: 2
For 10, prime factorization is : 21x51 
So, sum of the powers of primes is: 2
For 11, prime factorization is : 111 
So, sum of the powers of primes is: 1
For 12, prime factorization is : 22x 31 
So, sum of powers of primes is: 3
Therefore the total sum is 2+2+1+3=8.

Algorithm:

1. Initialize count to 0.
2. Iterate through numbers from 'a' to 'b'.
 For each number, factorize it and count the number of prime factors.
3. Return the total count.


The program takes input for the number of test cases, and for each test case, it takes 'a' and 'b' as input and outputs the result of the sumOfPowers function for that range.

*/

//Solution
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfPowers(int a, int b){
        
        int count = 0;
        
        for(int i = a; i <= b; i++) {
            int n = i;
            
            // Factorizing 'n' and counting the number of prime factors
            for(int j = 2; j <= sqrt(n); j++) {
                while(n % j == 0) {
                    count++;
                    n = n / j;
                }
            }
            
            // If 'n' is still greater than or equal to 2, it means it is a prime number
            if(n >= 2)
                count++;
        }
        
        return count;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int a, b;
        cin >>  a >> b;
        Solution obj;
        int ans = obj.sumOfPowers(a, b);
        cout << ans <<"\n";
    }
    return 0;
}
