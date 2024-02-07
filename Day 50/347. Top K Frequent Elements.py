#347. Top K Frequent Elements
'''
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Algorithm:

Count Frequencies:
Use Counter to count the frequencies of each element in the input list nums.
This step creates a dictionary-like object (freq_table) with elements as keys and their frequencies as values.
Most Common Elements:

Use most_common() on the freq_table to obtain a list of tuples representing elements and their frequencies.
The list (ans_table) is sorted in descending order based on frequencies.
Extract Top K Elements:

Iterate through the sorted list of tuples and extract the elements (keys) until the top k elements are obtained.
Append each element to the result list (ans).
Return Result:

Return the list of the top k frequent elements.


'''
from collections import Counter
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count frequencies
        freq_table = Counter(nums)
        
        # Get the most common elements
        ans_table = freq_table.most_common()
        
        # Extract top k elements
        ans = []
        for key, _ in ans_table:
            if k <= 0:
                break
            k -= 1
            ans.append(key)
        
        return ans
