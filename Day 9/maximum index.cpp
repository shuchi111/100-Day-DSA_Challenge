// maximum index 
/*
Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<A[1] so (j-i) is 1-0 = 1.


Approach -

Algorithm:

1. Initialize lmin and rmax arrays to store the minimum element to the left and maximum element to the right for each index.
2. Populate lmin array by iterating from left to right: lmin[i] = min(lmin[i-1], A[i]).
3. Populate rmax array by iterating from right to left: rmax[i] = max(rmax[i+1], A[i]).
4. Initialize maxIndexDiff to 0.
5. Use two pointers i and j to traverse the array:
While i and j are within bounds:
a. If lmin[i] <= rmax[j], update maxIndexDiff with max(maxIndexDiff, j - i) and increment j.
b. If lmin[i] > rmax[j], increment i.
6. Return maxIndexDiff.




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
    int maxIndexDiff(int A[], int N) 
    { 
        int n=N;
    vector<int>lmin(n);
    vector<int>rmax(n);
    
    lmin[0] = A[0];
    rmax[n-1] = A[n-1];
    
    for(int i=1;i<n;i++)
    {
        lmin[i] = min(lmin[i-1],A[i]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        rmax[i] = max(rmax[i+1],A[i]);
    }
    //printArray(lmin, n);
    //printArray(rmax, n);
    
    int maxIndexDiff = 0;
    int i = 0;
    int j = 0;
    while(i<N && j<N)
    {
        if(lmin[i]<=rmax[j])
        {
            maxIndexDiff = max(maxIndexDiff, j-i);
            j++;
        }
        else
        {
            i++;
        }
    }
    
    return maxIndexDiff;
    
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