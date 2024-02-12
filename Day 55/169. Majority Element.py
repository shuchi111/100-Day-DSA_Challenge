#169. Majority Element
'''
Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


//: This is the floor division operator in Python. It divides the left operand by the right operand and returns the largest integer less than or equal to the result.

'''

class Solution:
	def majorityElement(self, nums: List[int]) -> int:
		return sorted(nums)[len(nums) // 2]
		
