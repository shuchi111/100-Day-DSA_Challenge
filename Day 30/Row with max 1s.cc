// Row with max 1s
/*

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).


Algorithm: Row with Maximum 1s

1. Initialize max and index to 0 and -1, respectively.
2. Iterate through each row in the matrix:
Initialize count to 0.
For each element in the row, if it is 1, increment count.
 If count is greater than max, update max and set index to the current row.
3.  If index remains -1, no row contains a 1; return -1.
4. Otherwise, return the value of index



The algorithm implemented in the given code can be categorized as a Greedy Approach or more specifically, a Simple Iterative Approach for Row-wise Traversal

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
   int max=0;
   int index=-1;;
   for (int i = 0; i < n; i++) {
       int count=0;
            for (int j = 0; j < m; j++) {
                if(arr[i][j]==1){
                    count++;
                }
            }
            
            if(count > max){
                max=count;
                index=i;
            }
        }
        
        if(index == -1){
            return -1;
        }
        
        else{
            return index; 
        }
        
}
 
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
