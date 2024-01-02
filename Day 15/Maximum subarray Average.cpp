// leetcode -75 Q14 - Maximum average Subarray I
/*
 Approach - Sliding window
 
 Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75



Algorithm:

The goal of the algorithm is to find the maximum average of a subarray of length k within the given vector nums. The algorithm initializes the average (Avg) with the average of the first k elements and then iterates through the vector, updating the average for each new subarray of length k. The maximum average encountered during the iteration is the final result.

1. Initialize ans to the sum of the first k elements of nums.
2. Calculate the initial average (Avg) as ans / k.
3. Iterate from i = 1 to i = nums.size() - k:
Update ans by subtracting the element at index i - 1 and adding the element at index i + k - 1.
Update Avg by taking the maximum of the current Avg and the new average (ans / k).
4. Return the final maximum average, Avg.


*/

//solution

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Initialize ans with the sum of the first k elements
        double ans = 0;
        for (int i = 0; i < k; i++) {
            ans = ans + nums[i];
        }
        
        // Calculate the initial average (Avg)
        double Avg = ans / k;
        
        // Iterate from i = 1 to i = nums.size() - k
        for (int i = 1; i <= nums.size() - k; i++) {
            // Update ans by subtracting the element at index i - 1 and adding the element at index i + k - 1
            ans = ans - nums[i - 1] + nums[i + k - 1];
            
            // Update Avg by taking the maximum of the current Avg and the new average (ans / k)
            Avg = max(Avg, ans / k);
        }
        
        // Return the final maximum average
        return Avg;
    }
};
