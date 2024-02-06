
'''49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]



  '''

  class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}  # Initialize an empty dictionary for grouping anagrams
        for i in strs:
            temp = tuple(sorted(i)) #list is not hashable so converting to tuple
            d[temp] = d.get(temp, [])+[i] # Group anagrams using the sorted tuple as a key
        return d.values() # Return the lists of grouped anagrams
