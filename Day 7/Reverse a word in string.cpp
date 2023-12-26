// 151. Reverse Words in a String

/*Example -

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.


 Algo
1. Reverse Entire String:
Reverse the entire input string s.

2. Tokenization and Reverse:
Use a stringstream to tokenize the reversed string.
For each token, reverse it and append it to the result string (ans).

3. Remove Extra Space:
Remove the trailing space at the end of the result string.

4. Result:
The final result is a string where each word is reversed, and the order of words is reversed.

*/
// Solution
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string temp;
        string ans;

        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            ans+=' ';
        }

        ans.pop_back();
        return ans;
    }
};