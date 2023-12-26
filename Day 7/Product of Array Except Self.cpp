// Leetcode Q7 - 238. Product of Array Except Self

/*


1. Forward Pass:
Initialize mul as the first element of nums.
Iterate i from 1 to nums.size() - 1.
Set answer[i] to mul * answer[i-1].
Update mul to nums[i].

2. Backward Pass:
Initialize mul2 as the last element of nums.
Iterate j from nums.size() - 2 to 0 (decrementing).
Multiply answer[j] by mul2.
Update mul2 to mul2 * nums[j].

3.Result:
answer now contains the product of all elements except the one at the corresponding index.





Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]



*/

//Solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int mul = nums[0];
        answer[0]=1;
        for(int i=1; i<nums.size(); i++){
            answer[i] = mul * answer[i-1];
            mul = nums[i];
        }
        int mul2 = nums[nums.size()-1];
        for(int j=nums.size()-2; j>=0; j--){
            answer[j] *= mul2;
            mul2 *= nums[j];
        }
        return answer;
    }
};