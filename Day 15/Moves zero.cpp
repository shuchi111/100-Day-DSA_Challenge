//Day 15 revision day 
/*

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Algorithm:

The goal of the moveZeroes function is to move all the zeroes in a given vector nums to the end while maintaining the relative order of the non-zero elements. The algorithm uses a two-pointer approach, where one pointer (i) is used to keep track of the position to which non-zero elements should be moved, and the other pointer (j) traverses the array.

1. Initialization:
Initialize i to 0. This pointer represents the position where the next non-zero element should be placed.
Iterate over the array using a pointer j from 0 to n-1 (where n is the size of the vector).

2. Non-zero Element Found:
If nums[j] is not equal to 0 (i.e., a non-zero element is found):
Swap the element at position i with the element at position j. This ensures that non-zero elements are moved to the front of the array.
Increment i to prepare for the next non-zero element.

3. Zero-filling:
After the loop, there may be remaining positions after i where zero elements need to be filled.
Iterate over the remaining positions from i to n-1 and set the elements to 0. This step ensures that all zeroes are moved to the end while maintaining the relative order of non-zero elements.

*/
//Solution
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        // Iterate over the array
        for (int j = 0; j < n; j++) {
            // If a non-zero element is found
            if (nums[j] != 0) {
                // Swap non-zero element to the front
                std::swap(nums[i], nums[j]);
                // Increment the position for the next non-zero element
                i++;
            }
        }
        
        // Fill the remaining positions after i with zeroes
        for (int k = i; k < n; k++) {
            nums[k] = 0;
        }
    }
};


