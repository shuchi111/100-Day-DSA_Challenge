// 443. String Compression
/*

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".


Approach -
Algorithm:

1. Initialize a pointer i to keep track of the current position in the compressed array.
2. Iterate through the characters in the input vector (chars) starting from index 1 (j).
3. Maintain a count variable to keep track of consecutive repeating characters.
4. If the current character is different from the previous one or if it's the end of the array:
Store the current character in the compressed array at index i.
If the count is greater than or equal to 2, store its digits in the array.
Reset the count for the next character.
5. Increment the pointer i for each character added to the compressed array.
6. Return the final length of the compressed array.

*/

//solution 

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        for(int j=1,count=1;j<=chars.size();j++,count++){
            if(j==chars.size()||chars[j]!=chars[j-1]){
                chars[i++]=chars[j-1];
                if(count>=2){
                    for(char dig:to_string(count)){
                        chars[i++]=dig;
                    }
                }
            count=0;
            }
        }
        return i;
 }
};