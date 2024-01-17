// All Unique Permutations of an array

/*
Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.



Approach-
1. Sort the Array:
The input array arr is sorted in ascending order. Sorting is done to ensure that permutations are generated in lexicographically increasing order.

2. Generate Permutations using next_permutation:
The next_permutation function is utilized to generate permutations.
The do-while loop repeatedly calls next_permutation until all unique permutations are generated.

3. Store Permutations:
Each generated permutation is stored in the result vector.

4. Return Result:
The function returns the vector result containing all unique permutations.

*/
//solution
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> result;
    sort(arr.begin(), arr.end());  // Sort the array to ensure sorted permutations

    do {
        result.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));

    return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
