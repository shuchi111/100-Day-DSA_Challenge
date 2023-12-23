// valid substring

/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.



Algorithm:

1. Initialization:
Initialize vector v of size n with all elements as 0.
Initialize an empty stack st.

2. Process Parentheses Pairs:
Iterate i over the range [1, n-1].
If s[i] == ')' and st is not empty and st.top().first == '(':
Mark current position and st.top().second as valid pairs by setting v[i] = 1 and v[st.top().second] = 1.
Pop the top element from the stack.
Otherwise, push the current character and its position onto the stack.

3. Count Consecutive Valid Pairs:
Initialize variables c and m to 0 and INT_MIN.
Iterate i over the range [0, n-1].
If v[i] == 1, increment c.
If v[i] == 0, update m and reset c to 0.
Update m after the loop.

4. Return Maximum Count:
Return m as the result.


*/


//solution
int findMaxLen(string s) {
    int n = s.size();
    vector<int> v(n, 0);
    stack<pair<char, int>> st;
    
    // Process parentheses pairs using a stack.
    st.push({s[0], 0});
    for (int i = 1; i < n; i++) {
        if (s[i] == ')' && !st.empty() && st.top().first == '(') {
            v[i] = 1;
            v[st.top().second] = 1;
            st.pop();
        } else {
            st.push({s[i], i});
        }
    }
    
    int c = 0, m = INT_MIN;
    
    // Count consecutive valid pairs.
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            c++;
        } else {
            m = max(m, c);
            c = 0;
        }
    }
    // Update maximum count after the loop.
    m = max(m, c);
    
    return m;
}

//time and space complexity - O(n)