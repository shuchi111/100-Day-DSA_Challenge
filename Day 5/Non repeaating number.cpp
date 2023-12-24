// Non Repeating Numbers

/*

// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.



Approach -


1. Input: A vector a containing pairs of numbers.
2. Sort the vector a.
3. Initialize an empty vector ans to store the unique numbers.
4. Iterate through the sorted vector a.
If the current number is equal to the next number, skip the next number.
If the current number is not equal to the next number, add the current number to the ans vector.
5. Return the ans vector containing the two unique numbers.

*/

//Solutionn

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> a) 
    {
        // Code here.
        vector<int>ans;
        sort( a.begin(), a.end());
        for( int i =0; i<a.size(); i++)
        {
            if( a[i]==a[i+1])
            {
                ++i;
                
            }
            else{
                ans.push_back( a[i]);
            }
            }
        
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends