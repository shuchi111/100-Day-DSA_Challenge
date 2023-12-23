//  Activity Selection
/*

Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.



Approach 


Greedy Approach:
Initialize res to 1 (considering the first activity) and prev to 0.
Iterate from prev + 1 to n - 1.
For each activity i, check if the start time of i is greater than the finish time of the last selected activity (v[prev]).
If true, update prev to i and increment res.
Repeat this process for all activities.

Result:
The final result (res) represents the maximum number of non-overlapping activities that can be performed.


**Algorithm:
1. Convert the start and end vectors into pairs and store them in a vector v.
2. Sort the vector v based on the end times in ascending order.
3. Initialize res to 1 and prev to 0.
4. Iterate from prev + 1 to n - 1.
If v[i].second > v[prev].first, update prev to i and increment res.
5. Return the final result res.

*/

//solution 
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can


int activitySelection(vector<int> start, vector<int> end, int n) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i].first = end[i];
        v[i].second = start[i];
    }
    sort(v.begin(), v.end());
    int res = 1;
    int prev = 0;
    for (int i = prev + 1; i < n; i++) {
        if (v[i].second > v[prev].first) {
            prev = i;
            res++;
        }
    }
    return res;
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends