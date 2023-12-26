// Find all pairs with a given sum

/*


Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.


Algorithm 

1. Function Definition:
allPairs(A, B, N, M, X) takes arrays A and B, their sizes N and M, and integer X.
Returns pairs of elements from A and B whose sum is X in sorted order.

2. Initialization:
Initialize an empty vector ans and an unordered set s with elements of array A.

3. Check for Pairs:
Iterate over elements of array B.
If X - B[i] exists in set s, push (X - B[i], B[i]) to vector ans.

4. Sort the Result:
Sort vector ans based on the first element of each pair.

5. Return Result:
Return the sorted vector ans.

6.Main Function:
Read test cases, array sizes, and X.
Call allPairs and print results for each test case.
 
 7.Output:
Print pairs separated by commas. If no pair exists, print -1.

*/



//Solution 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }

    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X) {
        // Your code goes here
        vector<pair<int, int>> ans;
        unordered_set<int> s;

        for (int i = 0; i < N; i++) {
            s.insert(A[i]);
        }

       

        for (int i = 0; i < M; i++) {
            if (s.find(X - B[i]) != s.end()) {
                ans.push_back({X - B[i], B[i]});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends
