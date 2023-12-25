//Largest prime factor
/*
Given a number N, the task is to find the largest prime factor of that number.
 Example 1:

Input:
N = 5
Output:
5
Explanation:
5 has 1 prime factor i.e 5 only.


Algorithm:

1. Initialize maxi to 0.
2. Start a loop from i = 2 up to the square root of N.
While i is a factor of N:
Update maxi with the maximum of its current value and i.
Divide N by i.
3. After the loop, if N is greater than 1, update maxi with the maximum of its current value and N.
4. Return the value of maxi as the largest prime factor of the given N.


*/
//Solution

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor( long long int N){
        // code here
        long long int maxi = 0;
        long long int i;
        for( i =2; i*i<=N; i++){
            while(N%i==0){
                maxi = max(maxi, i);
                N=N/i;
                
            }
        }
        
        if(N>1){
            maxi= max(maxi, N);
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends