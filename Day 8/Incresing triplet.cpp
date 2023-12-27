// Leetcode 75- 8Q Increasing Triplet Subsequence

//Company - Amazon, Walmart, Factset
/*

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.







*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3)
            return false; // It's not possible to have an increasing triplet with less than 3 elements
        
        vector<int> t(n, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    t[i] = max(t[i], t[j] + 1);
                if (t[i] >= 3)
                    return true;
            }
        }
        
        return false;
    }
};

//time limit exceed