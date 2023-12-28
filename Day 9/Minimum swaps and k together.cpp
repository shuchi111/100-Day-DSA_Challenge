// Minimum swaps and k together

/*
Example 1:

Input : 
arr[ ] = {2, 1, 5, 6, 3} 
K = 3
Output : 
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}




Algorithm:

1. Initialize count to 0 to track the number of elements less than or equal to k.
2. Iterate through the array and increment count for each element less than or equal to k.
3. Initialize bad to 0 to track the number of elements greater than k in the first count elements.
4. Iterate through the first count elements and increment bad for each element greater than k.
5. Initialize ans to the current value of bad.
6. Use a sliding window approach to iterate through the array and find the minimum number of swaps:
a. If the element at index i is greater than k, decrement bad.
b. If the element at index j is greater than k, increment bad.
c. Update ans with the minimum of its current value and bad.
7. Return the final value of ans.

*/
//solution

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;
        
        // Count the number of elements less than or equal to k in the array.
        for (int i = 0; i < n; ++i)
            if (arr[i] <= k)
                ++count;

        int bad = 0;
        
        // Count the number of elements greater than k in the first 'count' elements.
        for (int i = 0; i < count; ++i)
            if (arr[i] > k)
                ++bad;

        int ans = bad;

        // Use a sliding window approach to find the minimum number of swaps.
        for (int i = 0, j = count; j < n; ++i, ++j) {
            if (arr[i] > k)
                --bad;
            if (arr[j] > k)
                ++bad;

            ans = min(ans, bad);
        }

        return ans;
    }
};
