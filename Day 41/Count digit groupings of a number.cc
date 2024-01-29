/*solution
Example 1: 

Input: 
str = "1119"
Output: 
7
Explanation: 
One valid grouping is {"1", "11", "9"}.
Sum of digits of first sub-group ("1") is 1,
for the second sub-group ("11"), it is 2,
and for the third one ("9"), it is 9.
As the sum of digits of the sub-groups is 
in increasing order, it forms a valid grouping.
Other valid grouping are {"1", "119"}, {"1","1","19"}, 
{"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
are six other valid groupings.


  */
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalCount(string str) {
        // Code here
        int n = str.length();
        vector<vector<int>>dp(n, vector<int>(1000, -1));
        return f(0, 0, str, dp);
    }
    int f(int i, int prevSum, string &s,vector<vector<int>> &dp) {
        int n = s.length();
        if (i == n) return 1;
        
        if(dp[i][prevSum]!=-1) return dp[i][prevSum];
        
        int ans = 0,currSum = 0;
        for (int k = i; k < n; k++) {
            currSum += s[k] - '0';
            if (currSum >= prevSum) {
                ans += f(k + 1, currSum, s, dp);
            }
        }
        
        return dp[i][prevSum] = ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
