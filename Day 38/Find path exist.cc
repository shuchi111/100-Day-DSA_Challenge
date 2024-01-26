/*Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.


Algorithm:
1. Initialize n and m as the number of rows and columns in the grid.
2. Create a 2D vector vis of size n x m to track visited cells.
3. Find the source cell (srcr, srcc) with value 1.
4. Create a queue and enqueue the source cell. Mark it as visited.
5. Perform BFS:
Dequeue a cell (r, c) from the queue.
Explore neighboring cells in four directions (up, right, down, left).
If a valid neighboring cell is found:
Mark it as visited.
If its value is 2, return true.
Enqueue the neighboring cell.
6. If the queue is empty and no destination cell with value 2 is found, return false.





  */
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {   
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int srcr=0,srcc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                        srcr=i;
                        srcc=j;
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({srcr,srcc});
        vis[srcr][srcc]=1;
        while(q.empty()==false)
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
               
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=0 && vis[nr][nc]==0)
                {
                    vis[nr][nc]==1;
                    if(grid[nr][nc]==2) return 1;
                    q.push({nr,nc});
                }
            }
        }
       
        return 0;
      
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends
