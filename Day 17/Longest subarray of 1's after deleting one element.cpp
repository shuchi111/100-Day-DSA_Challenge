// leetcode 75- Longest Subarray of 1's after deleting one element
/*
Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.



Algorithm-
1. Initialize pointers i and j at the start, ct0 to count zeros, total for subarray length, and mx for the maximum length.
2. Iterate j over the array:
a. If nums[j] is 0, increment ct0 and adjust pointers to have at most one zero in the subarray.
b. If nums[j] is not 0, increment total and update mx.
3. Return mx, unless it equals the array size, then return mx - 1.
*/

//Solution

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, ct0=0, total=0, mx=0;
        while(j<nums.size()){
            if(nums[j]==0){
                ct0++;
                while(ct0>1){
                    if(nums[i]==0) ct0--;
                    else total--;
                    i++;
                }
            }
            else{
                total++;
                mx=max(mx, total);
            }
            j++;
        }
        if(mx==nums.size()) return --mx;
        return mx;
    }
};