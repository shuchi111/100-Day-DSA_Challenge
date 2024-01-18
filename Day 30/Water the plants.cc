// Water the plants

/*

Input:
n = 6
gallery[] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: 
Sprinklers at index 2 and 5
can water the full gallery, span of
sprinkler at index 2 = [0,4] and span
of sprinkler at index 5 = [5,5].




Algorithm: Minimum Sprinklers to Cover Gallery

1. Initialize an empty vector of pairs v to store sprinkler intervals, and set target, i, and ans to 0.
2. Iterate through the gallery array, filter out invalid sprinklers, and populate v with effective coverage intervals.
3. Sort the vector v based on starting positions of intervals.
4. While the target is less than n and there are intervals left:
a. Update the target to the maximum coverage plus one.
b. Increment the number of sprinklers used (ans).
5. If the final target is less than n-1, return -1 (uncovered area); otherwise, return the number of sprinklers used (ans).


The approach used in the above code is a greedy algorithm with sorting.
  */
//solution
//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
                v.push_back({i-gallery[i], i+gallery[i]});
            }
        }
        int m=v.size();
        sort(v.begin(), v.end());
        int target=0, i=0, ans=0;
        while(target<n && i<m){
            if(v[i].first > target) return -1;
            
            int maxi=v[i].second; i++;
            while(i<m && v[i].first<=target){
                maxi=max(maxi, v[i].second);
                i++;
            }
            target=maxi+1;
            ans++;
        }
        if(target<n-1){
            return -1;
        }
        else{
            return ans;
        }
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends
