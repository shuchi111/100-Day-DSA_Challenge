# 198. House Robber

"""


Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

"""

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        # Base Cases
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])

        # Dynamic Programming Initialization
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        # Dynamic Programming Loop
        for i in range(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        # Return Result
        return dp[n - 1]
