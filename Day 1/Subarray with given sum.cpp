// Subarray with a given sum - Asked in Amazon, Facebook 
// GFG SDE Sheet

/*

Given an unsorted array A of size N that contains only non negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.


*/
//Solution - gfg Online portal
/*

Approach algorithm 


Algorithm:
The given code is a solution to find a continuous sub-array in an array arr such that the sum of elements in that sub-array is equal to a given number s. The algorithm uses a two-pointer approach to efficiently search for the sub-array.

1. Initialization:

Initialize two pointers i and j to 0.
Initialize a variable sum to the value of arr[0].
Initialize an empty vector v to store the result.
2. Sliding Window Technique:

Iterate while j is less than n.
If sum is equal to s, add the current sub-array indices (i+1, j+1) to the vector v and return v.
If sum is less than s, increment j and add arr[j] to sum.
If sum is greater than s:
If i < j, subtract arr[i] from sum and increment i.
If i >= j, increment both i and j and update sum to the value of arr[i].
No Sub-array Found:

If no sub-array is found within the loop, add -1 to the vector v to indicate that no such sub-array exists.
Return v.

*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s){
    int i=0,j=0,sum=arr[0];
        vector<int> v;
        while(j<n){
            if(sum==s){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(sum<s) sum+=arr[++j];
            else{
                if(i<j){
                    sum-=arr[i];
                    i++;
                }
                else{
                    i++;
                    j++;
                    sum=arr[i];
                }
            }
        }
        v.push_back(-1);
        return v;
    
    }
};





/*
There are three approaches-
1. Using nested loop

Steps -
i. Traverse the array from start to end.
ii. From every index start another loop from i to the end of the array to get all subarrays starting from i, and keep a variable currentSum to calculate the sum of every subarray.
iii. For every index in inner loop update currentSum = currentSum + arr[j]
iv. If the currentSum is equal to the given sum then print the subarray.


 A simple program to print subarray
with sum as given sum 

#include <bits/stdc++.h>
using namespace std;
 
/* Returns true if the there is a subarray
of arr[] with sum equal to 'sum' otherwise
returns false. Also, prints the result 
void subArraySum(int arr[], int n, int sum)
{
 
    // Pick a starting point
    for (int i = 0; i < n; i++) {
        int currentSum = arr[i];
 
        if (currentSum == sum) {
            cout << "Sum found at indexes " << i << endl;
            return;
        }
        else {
            // Try all subarrays starting with 'i'
            for (int j = i + 1; j < n; j++) {
                currentSum += arr[j];
 
                if (currentSum == sum) {
                    cout << "Sum found between indexes "
                         << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}
 
// Driver Code
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}


2. Dynamic programming

3. Sliding window

*/

