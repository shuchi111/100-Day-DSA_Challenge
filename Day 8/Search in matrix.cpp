//  Search in a matrix
/*
Example 1:

Input:
N = 3, M = 3
mat[][] = 3 30 38 
         44 52 54 
         57 60 69
X = 62
Output:
0
Explanation:
62 is not present in the
matrix, so output is 0


Approach - 

1. Start from the top-right corner of the matrix (i = 0, j = M - 1).
2. Loop until i is less than N and j is greater than or equal to 0.
3. Check the current element:
If it is equal to X, return 1.
If it is less than X, move down (i++).
If it is greater than X, move left (j--).
4. If the loop terminates without finding X, return 0.


*/

//Solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int matSearch(vector<vector<int>> &mat, int N, int M, int X) {
    int i = 0, j = M - 1;

    while (i < N && j >= 0) {
        if (mat[i][j] == X)
            return 1;
        else if (mat[i][j] < X)
            i++;
        else
            j--;
    }

    return 0;
}

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends



