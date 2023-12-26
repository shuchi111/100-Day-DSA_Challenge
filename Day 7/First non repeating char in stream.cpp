// First non-repeating character in a stream
/*

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.


Approach -

1. Initialization:
Initialize an empty queue (q) and a vector (f) to store character frequencies.
Initialize an empty string ans.

2.Traverse String:
For each character i in the input string A:
Increment frequency of i.
If frequency of i is 1, push i into the queue.
While the front of the queue has frequency > 1, pop from the queue.
If the queue is not empty, append the front character to ans; otherwise, append '#'.

3.Result:
The final result string ans contains the first non-repeating character at each step.





*/

//solution

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    vector<int> f( 26,0);
		    string ans = "";
		    
		    for( auto i:A){
		        ++f[i- 'a'];
		        
		        if( f[i -'a'] == 1)
		        q.push(i);
		        while(q.size() and f[q.front() -'a']>1)
		        q.pop();
		        
		        if( q.size())
		        ans+= q.front();
		        else
		        ans += '#';
		        
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends