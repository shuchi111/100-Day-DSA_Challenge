#2966. Divide Array Into Arrays With Max Difference

#solution
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        n=len(nums)
        ans=[]
        for i in range(2,n,3):
            if nums[i]-nums[i-2]>k:
                return []
            else:
                ans.append(nums[i-2:i+1])
        return ans            

"""
Algorithm:

1. Sort the Input Array: Sort the given array nums in ascending order.
2. Initialize Variables:
Set n to the length of the sorted array.
Initialize an empty list ans to store the resulting subarrays.
3. Iterate Over Sorted Array:
Iterate over the sorted array nums starting from the third element (i from 2 to n-1 with a step of 3).
Check if the difference between the current element (nums[i]) and the element two positions behind (nums[i-2]) is greater than k.
If the condition is true, return an empty list, indicating that it's not possible to form valid subarrays.
4. Form Subarrays:
If the condition is false, append a subarray consisting of the three consecutive elements (nums[i-2:i+1]) to the ans list.
5. Return Result:
Return the ans list containing the valid subarrays formed.


Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.
"""
