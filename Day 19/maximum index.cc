// Minimum index
/*

Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<A[1] so (j-i) is 1-0 = 1.


Algorithm:

1. Create a prefix minimum array (prefixMin).
2. Initialize prefixMin[0] and iterate to calculate the minimum from the left for each element.
3. Initialize two pointers i and j to n-1.
4. Initialize maxlen.
5. While i >= 0 and j >= 0, update maxlen and move pointers based on conditions.
6. Return maxlen.

*/
//Solution

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    {

        vector<int> prefixMin(n);
        prefixMin[0]=arr[0];
        for(int i=1;i<n;i++) {
            prefixMin[i]=min(prefixMin[i-1],arr[i]);
        }
        int i=n-1,j=n-1,maxlen=INT_MIN;
        while(i>=0 and j>=0) {
            if(prefixMin[i]<=arr[j]) {
                maxlen=max(maxlen,j-i);
                i--;
            } else j--;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends

