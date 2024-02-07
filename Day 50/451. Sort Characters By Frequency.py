'''

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Count Characters:
Use Counter to count character frequencies in the input string s.
Sort Tuples in Descending Order:
Create a list of tuples sorted by character frequencies in descending order.
Reconstruct Sorted String:
Use list comprehension to repeat each character by its count.
Return Result:
Join the characters to form the final sorted string.




'''

from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        # Create a list of tuples with sorted frequencies
        arr = sorted([(val, key) for key, val in Counter(s).items()], reverse=True)
        
        # Reconstruct the sorted string
        result = "".join([arr[i][1] * arr[i][0] for i in range(len(arr))])
        
        return result
