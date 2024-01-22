#645. Set Mismatch
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        duplicate=next(i for i in nums if nums.count(i)>1)
        missing=next(i for i in range(1,len(nums)+1) if i not in nums)
        return [duplicate, missing]
