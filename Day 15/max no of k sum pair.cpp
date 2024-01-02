// leetcode-75 Q13 - max number of k-sum pairs
/*

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.



Algorithm:

The goal of the algorithm is to find the maximum number of pairs in the nums vector such that their sum is equal to the given target k. The algorithm uses a two-pointer approach, sorting the array first and then incrementally adjusting the pointers based on the sum of elements.

1. Sort the nums vector in non-decreasing order.
2. Initialize pointers i and j at the beginning and end of the sorted array.
3. Initialize a variable count to 0 to keep track of the number of pairs.
4. Iterate while i < j:
If nums[i] + nums[j] == k, increment count and move both pointers inward (i++ and j--).
If nums[i] + nums[j] < k, increment i to explore larger values.
If nums[i] + nums[j] > k, decrement j to explore smaller values.
5. Return the final count.





*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int count = 0;
        
        // Iterate while i is less than j
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                // If the sum is equal to k, increment count and move both pointers inward
                count++;
                i++;
                j--;
            } else if (nums[i] + nums[j] < k) {
                // If the sum is less than k, increment i to explore larger values
                i++;
            } else {
                // If the sum is greater than k, decrement j to explore smaller values
                j--;
            }
        }
        return count;
    }
};
