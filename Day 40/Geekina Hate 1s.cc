//Geekina Hate 1s
/*
Example 1:

Input:
n = 5
k = 1
Output:
8
Explanation:
Following numbers are loved by Geekina -
0 = (0)2
1 = (1)2
2 = (10)2
4 = (100)2
8 = (1000)2




Algorithm:

Initialize a binary search range, low and high, with low = 0 and high = 1e18.
Use binary search to find the N-th number within the specified range.
In each binary search iteration, calculate the count of numbers with exactly K non-zero digits using the find function.
Adjust the binary search range based on the calculated count.
The find function converts the current number to binary representation and uses dynamic programming to count the numbers with exactly K non-zero digits.
The recursive function dpf is used to iterate through the binary representation and calculate the count for each possibility.
The dynamic programming table dp is used to store intermediate results and avoid redundant calculations.
Reset the dynamic programming table for each binary search iteration.
*/

//solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long findNthNumber(int n, int k) {
        long long low = 0, high = 1e18;
        dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(65, vector<long long>(65, -1)));
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long count = find(mid, k);
            if(count >= n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }


    long long find(long long n, int k){
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }

    long long dpf(string s, int n, int tight, int k){
        if(k < 0)
            return 0;
        if(n == 0){
            return 1;
        }
        if(dp[tight][k][n] != -1)
            return dp[tight][k][n];
        int ub = (tight == 1 ? (int)(s[s.length() - n] - '0') : 1);
        long long ans = 0;
        for(int dig = 0; dig <= ub; dig++){
            if(dig == ub)
                ans += dpf(s, n - 1, tight, k - dig);
            else
                ans += dpf(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = ans;
    }

    void reset(){
        for(int i = 0; i < 65; i++){
            for(int j = 0; j < 65; j++){
                dp[0][i][j] = dp[1][i][j] = -1;
            }
        }
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
