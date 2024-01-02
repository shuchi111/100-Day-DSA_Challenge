//Leetcode - Q11 [ Is Subsequence ] by two pointer
/*

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true




This two-pointer approach efficiently determines whether string s is a subsequence of string t by maintaining the order of characters in s while iterating through t.

Algorithm: isSubsequence(s, t)

1. Initialization:
Initialize a pointer j to 0 for string s.

2. Iterate through characters of t:
For each character at index i in string t:
If t[i] is equal to s[j], increment j to move to the next character in s.

3. Completion Check:
After the loop, check if j is equal to the length of string s.
If true, return true as s is a subsequence of t.
If false, return false as not all characters in s were found in the correct order in t.


*/

// Solution

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        
        // Iterate through the characters of t
        for (int i = 0; i < t.length(); i++) {
            // Check if the current character in t matches the current character in s
            if (t[i] == s[j]) {
                // Increment j to move to the next character in s
                j++;
            }
        }
        
        // Check if s is completely iterated through
        if (j == s.length()) {
            return true;
        }
        
        // s is not a subsequence of t
        return false;
    }
};
