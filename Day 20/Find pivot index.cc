//724. Find Pivot Index
/*

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Algorithm

1. Sum Calculation:
Initialize a variable t to 0 to store the total sum of elements in the array.
Iterate through each element in nums and add it to t.

2. Pivot Index Search:
Initialize a variable temp to 0 to store the running sum of elements on the left side of the current index.
Iterate through the elements of nums using a for loop.
Inside the loop:
Add the current element to temp.
Check if the current element is the pivot index by comparing nums[i] with t - 2 * temp.
If true, return the current index i.
If no pivot index is found, return -1.


*/
//Solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t = 0;
        for (int num : nums) t += num;
        int temp = 0;
        for (int i = 0; i < nums.size(); temp += nums[i++])
            if (nums[i]==t-2*temp)
                return i;
        return -1;
    }
};
