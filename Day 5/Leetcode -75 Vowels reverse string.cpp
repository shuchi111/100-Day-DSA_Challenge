// Leetcode -75 - Reverse vowels of a string

/*

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"


Approach -
Two pointer


*/
// Solution


//Simply using  Two pointer technique
class Solution {
public:
    bool isVowel(char &ch) {
        return ch =='a' || ch == 'e' ||
               ch =='i' || ch == 'o' ||
               ch == 'u' ||
               ch =='A' || ch == 'E' ||
               ch =='I' || ch == 'O' ||
               ch == 'U';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            if(!isVowel(s[i])) i++;
            
            else if(!isVowel(s[j])) j--;
            
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};

