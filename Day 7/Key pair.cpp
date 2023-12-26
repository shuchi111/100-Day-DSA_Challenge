// Key pair 
/*

Example 1:

Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16


Algorithm-

1. Input: arr (array of integers), n (size of the array), x (target sum).
2. Sort the array arr in ascending order.
3. Initialize two pointers l and h at the beginning and end of the array, respectively.
4. Use a while loop until l is less than h.
Calculate the sum arr[l] + arr[h].
If the sum is equal to x, return true.
If the sum is greater than x, decrement h.
If the sum is less than x, increment l.
5. If the loop completes without finding a pair, return false.





*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
// Function to check if array has 2 elements
// whose sum is equal to the given value
bool hasArrayTwoCandidates(int arr[], int n, int x) {
    // code here
  sort(arr,arr+n);
int l=0;
    int h=n-1;
    while(l<h){
        int sum=arr[l]+arr[h];
        if(sum==x){
            return true;
        }
        else if(sum>x){
            h--;
        }
        else{
            l++;
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends