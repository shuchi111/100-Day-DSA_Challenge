// Day 11 -Parenthesis Checker
/*
Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.



Algorithm:

Create a stack to store the opening brackets.
Iterate through each character in the given string.
If the character is an opening bracket ({, (, or [), push it onto the stack.
If the character is a closing bracket (}, ), or ]), check if the stack is not empty and the corresponding opening bracket matches the one at the top of the stack. If it does, pop the opening bracket from the stack.
If any of the above conditions fail, return false, as the brackets are not balanced.
After processing all characters, check if the stack is empty. If it is, return true (balanced brackets); otherwise, return false.
Approach:

Use a stack to keep track of the opening brackets.
When encountering a closing bracket, check if the stack is not empty and if the corresponding opening bracket matches.
Return false if any mismatch is found or if there are remaining opening brackets in the stack.


*/


//Solution
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int l = x.length();
        stack<char>s;
        for(int i=0;i<l;i++)
        {
            if((x[i] == '{') || (x[i] =='(') || (x[i] =='['))
            {
             s.push(x[i]);
            }
            else
            {
                if( (s.empty() == true) || (cheak(s.top(),x[i]) != true) ) return false;
                s.pop();
            }
        }
        
        return s.empty()? true: false;
    }
    bool cheak(char i, char j)
    {
     if(i == '{' && j == '}') return true;
     if(i == '(' && j == ')') return true;
     if(i == '[' && j == ']') return true;
     return false;
    }

};