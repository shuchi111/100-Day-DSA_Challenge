// Chocolate disrtibution problem

/*
problem -
Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.




Algorithm

1. Sort the given vector a in non-decreasing order.
2. Initialize a variable ans to store the minimum difference, initially set to LONG_MAX (maximum value representable by the long data type).
3. Iterate through the sorted array from index 0 to n-m+1 (inclusive).
For each subarray of size m, calculate the difference between the maximum and minimum elements.
Update ans if the calculated difference is smaller than the current ans.
4. After the loop, ans contains the minimum difference between the maximum and minimum elements in any subarray of size m.
5. Return the value of ans.

*/
//solution 

class Solution{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // Sort the vector in non-decreasing order
        sort(a.begin(), a.end());

        // Initialize ans to store the minimum difference
        long ans = LONG_MAX;

        // Iterate through subarrays of size m
        for (int i = 0; i <= n - m; i++) {
            int j = i + m - 1;
            
            // Calculate the difference between max and min elements in the subarray
            long diff = a[j] - a[i];
            
            // Update ans if the current difference is smaller
            if (diff < ans)
                ans = diff;
        }

        // Return the minimum difference
        return ans;
    }
};

// A short code

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort( a.begin(), a.end());
    long long ans = 1e9;
    for( int i =m-1; i<n; i++){
        ans = min ( ans, a[i] - a[i-(m-1)]);
        
    }
    return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends

/*
Approach of last code 
1. Sort the given vector a in non-decreasing order.
2. Initialize a variable ans to a large value (1e9 is used to represent infinity).
3. Iterate through the array from index m-1 to n-1.
For each subarray of size m, calculate the difference between the maximum and minimum elements.
Update ans with the minimum of the current ans and the calculated difference.
4. After the loop, ans contains the minimum difference between the maximum and minimum elements in any subarray of size m.
5. Return the value of ans.

*/