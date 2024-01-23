// Course Schedule
/*


Algorithm:

Problem Description:

Given numCourses courses labeled from 0 to numCourses - 1 and prerequisites represented by pairs of the form [a, b], where a is a prerequisite for b.
Determine the possible ordering of courses that satisfies all prerequisites.

Approach:
Create an adjacency list (adj) and an indegree vector (indeg).
Iterate over prerequisites to build the adjacency list and calculate the indegrees.
Use a queue for topological sorting, starting with courses having an indegree of 0.
Enqueue courses with an indegree of 0.
While the queue is not empty:
Dequeue a course (k).
Add k to the result.
Decrease the indegree of courses dependent on k.
If the indegree of any dependent course becomes 0, enqueue that course.
If the size of the result equals numCourses, return the result; otherwise, return an empty vector.

Time Complexity:
O(V + E), where V is the number of courses (numCourses) and E is the number of prerequisites (m).

  */
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[numCourses];
        vector<int>indeg(numCourses,0);
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            for(auto job:adj[i])
            {
                indeg[job]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int k=q.front();
            ans.push_back(k);
            q.pop();
            for(auto j:adj[k])
            {
                indeg[j]--;
                if(indeg[j]==0)
                    q.push(j);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
