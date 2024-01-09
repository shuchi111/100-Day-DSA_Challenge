//Search Pattern (KMP-Algorithm)
/*
Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 

  */


//Solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>ans;
            int n = txt.size();
            int m = pat.size();
            for(int i=0;i<n;i++){
                if(txt[i]==pat[0]){
                    int j =i;
                    int k = 0;
                    for(k;k<m;k++){
                        if(pat[k]!=txt[j]) break;
                        j++;
                    }
                    if(k==m){
                        ans.push_back(i+1);
                    }
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
