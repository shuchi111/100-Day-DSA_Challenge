//Rat in a Maze Problem - I

/*


Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.


 move are 'U'(up), 'D'(down), 'L' (left), 'R' (right)

Algorithm-
1. Helper Function 'solve':
Base Case: If at the destination, add the current path to the results.
Try moving in four directions: Down, Left, Right, Up.
Recursively explore valid moves, marking visited cells.
Backtrack by undoing the cell marking.

2. Main Function findPath:
Initialize results vector and visited array.
Check if starting cell is open, call solve function.
Return the results vector.

Note: The algorithm explores all possible paths in the maze using backtracking.
 
*/
//Solution
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++



class Solution{
    public:
     void solve(int i,int j,int  n,vector<vector<int>>&a,vector<string>&ans ,              string str,int di[],int dj[],vector<vector<int>>&vis){

 //base condition

     if(i==n-1&&j==n-1){
            ans.push_back(str);
            return;
        }
        
       string st="DLRU";
       for(int k=0;k<4;k++){
           int p=i+di[k];
           int q=j+dj[k];
           if(p>=0&&q>=0&&p<n&&q<n&&!vis[p][q]&&a[p][q]==1){
               vis[i][j]=1;
               solve(p,q,n,a,ans,str+st[k],di,dj,vis);
               vis[i][j]=0;
           }
       }
       
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int di[]={1,0,0,-1};
        int dj[]={0,-1,1,0};
        if(m[0][0]==1){
            solve(0,0,n,m,ans,"",di,dj,vis);
        }
        return ans;
        
    }
};
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
