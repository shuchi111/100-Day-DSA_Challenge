// minimum platform 
/*

Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.



Algorithm:

Algorithm (Short):

1. Sort arrival (arr) and departure (dep) arrays.
2. Initialize ans to INT_MIN, a to 1, and b to 0.
3. While a < n:
a. Update ans to the maximum of its current value and a - b.
b. If arr[a] <= dep[b], increment a; else, increment b.
4. Update ans for remaining trains: ans = max(ans, a - b).
5. Return ans as the minimum platforms required.

*/

//Solution
//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)

    {

     // Your code here

     sort(arr,arr+n);

     sort(dep,dep+n);

     int ans=INT_MIN;

     int a=1,b=0;

     while(a<n)

     {

         ans=max(ans,a-b);

         if(arr[a]<=dep[b])a++;

         else b++;

     }

     ans=max(ans,a-b);

     return ans;

    }


};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends


