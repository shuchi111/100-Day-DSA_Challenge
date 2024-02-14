'''
Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.


Algorithm:

1. Iterate through each word in the given list of words.
2. For each word, check if it is a palindrome by comparing the word with its reverse (word == word[::-1]).
3. If a palindrome word is found, return that word.
4. If no palindrome word is found after checking all words, return an empty string.


'''

class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if word==word[::-1]:
                return word
        return ""   
