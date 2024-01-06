// kadane's Algorithm
/*

Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.


Algorithm:

1. Initialize csum = 0, msum = INT_MIN
2. Iterate through the array:
    a. Update csum += arr[i]
    b. If csum > msum, update msum = csum
    c. If csum < 0, reset csum to 0
3. Return msum
*/

//Solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
     long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long csum=0;
        long long msum=INT_MIN;
        for(int i=0;i<n;i++){
             csum += arr[i];
        if(csum > msum)  msum = csum;
        if(csum < 0) csum=0;
        }
        return msum;
      
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
