//Solution


class Solution {
  public:
    string removeKdigits(string S, int k) {
        int n = S.size();
        stack<char> myStack;
        
        for(auto c : S) {
            while(!myStack.empty() && k > 0 && myStack.top() > c) {
                myStack.pop();
                k--;
            }
            
            if(!myStack.empty() || c != '0'){
                myStack.push(c);
            }
        }
        
        // if string in incresing oder
        while(!myStack.empty() && k--) {
            myStack.pop();
        }
        
        if(myStack.empty()){
            return "0";
        }
        
        while(!myStack.empty()){
            S[n-1] = myStack.top();
            myStack.pop();
            n--;
        }
        
        return S.substr(n);
    }
};
