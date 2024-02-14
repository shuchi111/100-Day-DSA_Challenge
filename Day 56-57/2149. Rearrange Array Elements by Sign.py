'''
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 



Algorithm:

1. Create two lists, positives and negatives, to separate positive and negative integers from the given nums array.
2. Use a loop to rearrange the array by alternating between positive and negative integers.
 Iterate over the positions with a step of 2 using enumerate(range(0, len(nums), 2), start=0).
At each position, assign the corresponding positive and negative integers from their respective lists to the nums array.
3. Return the modified nums array as the final result.

'''



class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        negatives = [i for i in nums if i<0]
        positives = [i for i in nums if i>=0]
        for index,position in enumerate(range(0,len(nums),2), start=0):
            nums[position]=positives[index]
            nums[position+1]=negatives[index]
        return nums
