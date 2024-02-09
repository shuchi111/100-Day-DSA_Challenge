#368. Largest Divisible Subset
'''

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.




Algorithm:

Sort the Input:
Sort the input list nums in ascending order. Sorting ensures that if nums[i] is divisible by nums[j], then nums[j] will always come before nums[i] in the sorted list.
Dynamic Programming:
Initialize a 2D array arr where arr[i] represents the largest divisible subset ending at index i.
Iterate over each pair of indices (i, j) where i is the current index and j ranges from 0 to i-1.
If nums[i] is divisible by nums[j] and the size of the subset ending at index i (len(arr[i])) is less than the size of the subset ending at index j plus one (len(arr[j]) + 1), update arr[i] to be a copy of arr[j] followed by nums[i].
Sort by Subset Size:
After constructing the array arr, sort it in descending order based on the size of each subset.
Return the Largest Subset:
Return the first element of the sorted arr as it represents the largest divisible subset.
'''

from typing import List

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # Step 1: Sort the input
        nums.sort()
        
        # Step 2: Dynamic Programming to find largest divisible subset
        arr = [[num] for num in nums]
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(arr[i]) < len(arr[j]) + 1:
                    arr[i] = arr[j] + [nums[i]]
        
        # Step 3: Sort by subset size
        arr.sort(key=len, reverse=True)
        
        # Step 4: Return the largest subset
        return arr[0]
