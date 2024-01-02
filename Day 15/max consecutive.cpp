//leetcode 75 [Q 15] - 1004. Max consecutive ones III
/*

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.



Algorithm:

The algorithm aims to find the length of the longest subarray of 1s in the given nums vector with at most k zeros that can be flipped to 1s. It uses a sliding window approach to maintain a subarray with the maximum number of 1s.

1. Initialize variables count to 0 (representing the current count of 1s), start to 0 (representing the start index of the current subarray), and max_count to -1 (to store the maximum count of 1s encountered).
2. Iterate through the nums vector from index i = 0 to nums.size() - 1.
If nums[i] is 1, increment count.
If nums[i] is 0:
If k > 0, flip the 0 to 1, increment count, and decrement k.
If k == 0, shrink the subarray from the left (start) until k becomes non-zero. Increment start and decrement k or decrement count as needed.
Update max_count with the maximum of the current count and max_count.
3. Return max_count.

*/

// solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;         // Current count of 1s
        int start = 0;         // Start index of the current subarray
        int max_count = -1;    // Maximum count of 1s encountered

        // Iterate through the nums vector
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;  // Increment count for 1s
            } else if (nums[i] == 0) {
                if (k > 0) {
                    count++;  // Flip 0 to 1, increment count, and decrement k
                    k--;
                } else {
                    // Shrink subarray from the left until k becomes non-zero
                    while (k == 0) {
                        if (nums[start] == 0) {
                            start++;
                            k++;
                            count--;
                        } else {
                            start++;
                            count--;
                        }
                    }
                    count++;  // Increment count after shrinking
                    k--;
                }
            }

            // Update max_count with the maximum of current count and max_count
            max_count = max(max_count, count);
        }

        // Return the maximum count of 1s encountered
        return max_count;
    }
};
