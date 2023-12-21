//Leetcode -75 - Greatest common divisor

/*
Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"



Algorithm:

1. Calculate the lengths of the input strings n1 and n2.
2. Check if the concatenation of str1 + str2 is equal to str2 + str1. This condition ensures that the strings have a common prefix.
 If the condition is not satisfied, return an empty string since there is no common prefix.
3. If the condition is satisfied, find the GCD of n1 and n2 using the gcd function.
4. Return the substring of str1 from index 0 to the length of the GCD.

*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      int n1 = str1.size();
      int n2 = str2.size();
      if(str1 + str2 != str2 + str1) 
      {
          return "";
      }
      return str1.substr(0,gcd(n1,n2));
    }
};