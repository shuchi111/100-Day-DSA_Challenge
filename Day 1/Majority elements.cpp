// Majority Element
/*

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array


Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.


Approach -
1.  loop
2. Binary search tree
 ( Moore's voting algorithm )
 
 Voting Algorithm:

The first loop iterates through the array.
If count is 0, it means we have encountered a potential majority element, so we update el to the current element.
If the current element is equal to el, we increment count because it supports the potential majority element.
Otherwise, we decrement count as the current element opposes the potential majority element.
Check Majority Element:

After the first loop, el contains the potential majority element.
The second loop iterates through the array again to count the occurrences of the potential majority element.
If the count is greater than size/2, the potential majority element is indeed a majority element, so it is returned.
If the count is not greater than size/2, there is no majority element, and -1 is returned.
 


*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    
    {
        int el =0;
        int count = 0;
        for( int i = 0; i<size; i++){
        if( count==0 ){
            el = arr[i];
            
        }
        if( el == arr[i]) count++;
        else count--;
            
        }
        count =0;
        for( int i =0; i<size; i++){
            if( el== arr[i]){
                count++;
            }
        }
        if( count>size/2){
            return el;
        }
        return -1;
        
   
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends