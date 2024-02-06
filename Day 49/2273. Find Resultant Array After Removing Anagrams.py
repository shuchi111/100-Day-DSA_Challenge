#2273. Find Resultant Array After Removing Anagrams
'''
Example 2:

Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.

'''
#solution

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        returned = [words[0]]  
        for i in range(len(words)-1):
            if sorted(words[i]) != sorted(words[i+1]):
                returned.append(words[i+1])
        return returned
