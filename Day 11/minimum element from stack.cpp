// Get minimum elememt from stack

/*

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query 
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack 
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2 
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1


Algorithm: Min Stack

1. Initialization:
Initialize a stack of pairs to store elements and their corresponding minimum values.
Each pair in the stack consists of the current element x and the minimum element (min_element) seen so far.

2. Push Operation (push(x)):
If the stack is empty, push the pair (x, x) onto the stack.
Otherwise, push the pair (x, min(s.top().second, x)) onto the stack, updating the minimum element.

3. Pop Operation (pop()):
Pop the top element from the stack and return it.

4. Get Minimum Operation (getMin()):
If the stack is empty, return -1 (indicating that the stack is empty).
Otherwise, return the second component of the top pair in the stack, which represents the minimum element.



*/

// Solution
class Solution{
    stack<pair<int,int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) return -1;
           return s.top().second;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(s.empty()) return -1;
            int a = s.top().first;
            s.pop();
            return a;
            //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()) s.push({x,x});
           else s.push({x,min(s.top().second,x)});
           //Write your code here
       }
};
