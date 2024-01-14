// Find duplicate rows in a binary matrix
/*
Example 1:

Input:
R = 2, C = 2
matrix[][] = {{1, 0},
            {1, 0}}
Output: 
1
Explanation:
Row 1 is duplicate of Row 0.


Algorithm:

1. Initialize an empty hash set (mp) to keep track of rows.
2. Initialize an empty vector (ans) to store the indices of repeated rows.
3. Iterate through each row of the matrix.
Convert the row into a string (str) by appending each element as a character.
Check if the string is already present in the hash set (mp).
If it is, add the index of the current row to the result vector (ans).
Otherwise, add the string to the hash set.
4. Return the result vector (ans).

*/
//Solution
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

    class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int> ans;
        unordered_map<string, bool> mp;
        
        for(int i=0; i<M; i++){
            
            string str = "";
                
            for(int j=0; j<N; j++){
                
                char ch = matrix[i][j] + '0';
                str += ch;
            }
            
            if(mp[str] == 1){
                ans.push_back(i);
            }
            mp[str] = 1;
        }
        
        return ans;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends
