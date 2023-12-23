// Max length chain
//longest incresing subsequence

/*


You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs.  
Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}


Approach 
1. Convert the given array of pairs p into a vector v with swapped positions of p[i].first and p[i].second.
2. Sort the vector v based on the end of the chain in ascending order.
3. Initialize ans to 0 and mx to 0.
4. Iterate through each pair in the sorted vector v.
If v[i].second > mx, update ans++ and mx to v[i].first.
5. Return the final result ans.

*/

// solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        vector<pair<int,int>> v;
        for(int i=0; i<n ;i++)
        {
            v.push_back({p[i].second,p[i].first}); 
        }
        sort(v.begin(),v.end());
        int ans=0,mx=0;
        for(int i=0; i<n ;i++)
        {
            if(v[i].second>mx)
            {ans++;mx=v[i].first;}
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends