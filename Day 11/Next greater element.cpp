//Nect larger element 
/*

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.


Algorithm:

1. Initialize an empty stack and an empty result vector.
2. Iterate the array from right to left.
Pop elements from the stack until the top is greater than the current array element.
If the stack is empty, push -1 onto the result vector.
If the stack is not empty, push the top of the stack onto the result vector.
Push the current array element onto the stack.
3. Reverse the result vector to get the final answer.


*/

//Solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
     vector<long long> nextLargerElement(vector<long long> arr, int n) {
        stack<long long> st;
        vector<long long> v1;

        // Iterate the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack until the top is greater than arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack is empty, no greater element found
            if (st.empty()) {
                v1.push_back(-1);
            } else {
                v1.push_back(st.top());
            }

            // Push the current element onto the stack
            st.push(arr[i]);
        }

        // Reverse the result vector to get the final answer
        reverse(v1.begin(), v1.end());
        return v1;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends