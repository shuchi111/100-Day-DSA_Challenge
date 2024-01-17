//Longest consecutive subsequence
/*

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.


Approach-
1. Create an unordered_map m to store the frequency of each element in the array.
2. Iterate through the array to populate m and find the maximum element maxel.
3. Iterate from 0 to maxel.
If i is present in m, increment cnt and update maxi if cnt is greater than maxi.
If i is not present, reset cnt to 0.
4. Return the maximum length maxi.

The function returns the length of the longest consecutive subsequence in the array.

*/
//solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
   int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        int maxi=0,cnt=0,maxel=0;
        unordered_map<int,int> m;
        for(int i=0;i<N;i++)
        {
            m[arr[i]]++;
            maxel=max(maxel,arr[i]);
        }
        for(int i=0;i<=maxel;i++)
        {
            if(m.find(i)!=m.end())
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else cnt=0;
            
        }
        return maxi;
    }
};



//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
