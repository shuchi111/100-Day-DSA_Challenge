'''
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.Example 1:

Algorithm:

1. Convert the input string s to a list of lowercase alphanumeric characters using list comprehension.
2. Check if the obtained list is equal to its reverse (s == s[::-1]).
3. Return True if the string is a palindrome, and False otherwise.


'''

class Solution:
    def isPalindrome(self, s: str) -> bool:
    	s = [i for i in s.lower() if i.isalnum()]
    	return s == s[::-1]
