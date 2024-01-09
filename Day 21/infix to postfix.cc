//infix to postfix
/*
Algorithm:

Create a stack to store operators.
Create an empty string res to store the postfix expression.
Traverse the infix expression from left to right.
If the current character is an operand (operand includes lowercase and uppercase letters, and digits), append it to res.
If the current character is an opening parenthesis '(', push it onto the stack.
If the current character is a closing parenthesis ')', pop operators from the stack and append them to res until an opening parenthesis '(' is encountered. Pop and discard the opening parenthesis.
If the current character is an operator (+, -, *, /, ^), pop operators from the stack and append them to res until an operator with lower precedence or an opening parenthesis '(' is encountered. Push the current operator onto the stack.
After traversing the entire expression, pop any remaining operators from the stack and append them to res.
The final res is the postfix expression.


The Shunting Yard Algorithm is a method for parsing mathematical expressions, specified in infix notation. Its primary purpose is to convert an infix expression into a postfix expression, which is often more convenient for evaluation.

Algorithm:
1. Initialize two stacks - one for operators (operatorStack) and one for output (outputQueue).
2. Scan the infix expression from left to right.
3. For each element in the input:
If the element is an operand (number or variable), add it to the output queue.
If the element is an operator:
While there is an operator at the top of the operatorStack with greater precedence or equal precedence and left-associativity:
Pop the operator from the operatorStack and add it to the output queue.
Push the current operator onto the operatorStack.
If the element is an open parenthesis '(', push it onto the operatorStack.
If the element is a close parenthesis ')':
While the top of the operatorStack is not an open parenthesis:
Pop operators from the operatorStack and add them to the output queue.
Pop the open parenthesis from the operatorStack.
4. After scanning the entire expression, pop any remaining operators from the operatorStack and add them to the output queue.
5. The elements in the output queue represent the postfix notation of the infix expression.

*/
// Solution
class Solution {
public:
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*'|| c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }

string infixToPostfix(string s) {
        stack<char>st;
        string res;
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
                res+=s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prec(st.top())>=prec(s[i])){
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};

