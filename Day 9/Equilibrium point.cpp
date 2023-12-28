// Equilibrium point

/*


Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2).

Approach -
Algorithm:

1. ,If the array has only one element, return 1 as it is the equilibrium point.
2. Calculate the total sum of all elements in the array.
3. Initialize a variable left to 0.
4. Iterate through each element in the array.
a. Check if the current index is an equilibrium point by comparing left with (sum - left - a[i]).
b. If true, return the 1-based index of the equilibrium point.
c. Update left by adding the current element to it.
5. If no equilibrium point is found after the loop, return -1.


*/

//code
//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n==1) return 1;
    
        // Your code here
        long long int sum = 0;
        for( int i =0; i<n; i++){
            sum+=a[i];
        }
        
        long long left = 0;
        for( int i =0; i<n; i++){
            if( left==(sum -left -a[i])) return i+1;
            left += a[i];
            
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends