'''

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Algorithm:

1. Separate the odd and even integers from the input list nums into two separate lists, odd and even, using list comprehensions.
2. Initialize an empty list result to store the final sorted array.
3. Iterate through the indices of the odd list (since odd and even lists have the same length).
Append the k-th element of the even list to the result.
Append the k-th element of the odd list to the result.
4. Return the final sorted array result.


'''
# list comprefension
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd = [i for i in nums if i%2!=0]
        even = [j for j in nums if j%2==0]
        result=[]
        for k in range(len(odd)):
            result.append(even[k])
            result.append(odd[k])
        return result
