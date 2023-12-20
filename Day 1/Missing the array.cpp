// Find the missing Number

/*

Problem -

Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.


Note: There are no duplicates in the list.

Examples: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: Here the size of the array is 7, so the range will be [1, 8]. The missing number between 1 to 8 is 5



There are 5 approach to solve this- Explore here https://www.geeksforgeeks.org/find-the-missing-number/
1. Using Hasing  
2. Using summation of first N natural numbers
3. Using binary operations
4. Using Cyclic Sort
5. Use elements as Index and mark the visited places as negative



problem -2 to solve is below
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.


Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4




Initialize XOR Result:

Initialize a variable res to 0. This variable will be used to store the XOR result.
XOR with Expected Sequence:

Iterate from i = 1 to n (inclusive).
Perform XOR operation (res ^= i) with the expected sequence of numbers from 1 to n.
XOR with Array Elements:

Iterate from i = 0 to n-1.
Perform XOR operation (res ^= array[i]) with the elements of the given array.
Return Result:

The final value of res is the missing number.

*/



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int res = 0;
        for( int i =1; i<=n; i++)res^=i;
        
        for( int i =0; i <n-1; i++ ) res^= array[i];
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends