//Sliding window 

/*


Window Sliding Technique is a computational technique that aims to reduce the use of nested loops and replace it with a single loop, thereby reducing the time complexity.


***we use the Sliding Window then we remember the following terms which is mentioned below:

 [Array, String, Sub Array, Sub String, Largest Sum, Maximum Sum, Minimum Sum ]
 
 
 
 Approach - 
 
1. Create two variables, start=0, currentSum = arr[0]
2. Traverse the array from index 1 to end.
3. Update the variable currentSum by adding current element, currentSum = currentSum + arr[i]
4. If the currentSum is greater than the given sum, update the variable currentSum as currentSum = currentSum – arr[start],
5. and update start as, start++.
6. If the currentSum is equal to given sum, print the subarray and break the loop.




*/

#include <iostream>
using namespace std;
 
/* Returns true if the there is a subarray of
arr[] with a sum equal to 'sum' otherwise
returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize currentSum as value of
    first element and starting point as 0 */
    int currentSum = arr[0], start = 0, i;
 
    /* Add elements one by one to currentSum and
    if the currentSum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If currentSum exceeds the sum,
        // then remove the starting elements
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
 
        // If currentSum becomes equal to sum,
        // then return true
        if (currentSum == sum) {
            cout << "Sum found between indexes " << start
                 << " and " << i - 1;
            return 1;
        }
 
        // Add this element to currentSum
        if (i < n)
            currentSum = currentSum + arr[i];
    }
 
    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
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