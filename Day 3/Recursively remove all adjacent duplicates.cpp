// Recursively remove all adjacent duplicates

/*



Input -
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgk



Remove Adjacent Duplicates (rremove):
Repeat the following steps until no more adjacent duplicates are found:
Initialize an empty string temp.
Initialize an index i to traverse the original string.
While i is less than the size of the original string (n):
Initialize an index j to find the end of the current group of adjacent duplicates (i+1).
While the character at position i is equal to the character at position j and j is less than n, increment j.
If j is equal to i+1, append the character at position i to the temp string.
Set i to j.
Update the original string with the contents of the temp string.
*/


//Solution

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        while(1){
        // code here
        int i =0,n=s.size();
        string temp;
        while(i<n){
            int j =i+1;
            while(s[i]==s[j] && j<n) j++;
            if( j==i+1) temp +=s[i];
            i = j;
        }
        if(s.size() == temp.size()) break;
        s=temp;
    }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends