// Hackerearth Q6 - Split houses

/*

Certainly! The given code appears to solve a problem related to assigning colors to cells based on the presence of characters 'H' or '.' in a string s. The goal is to determine if it's possible to color the cells such that no two consecutive cells have 'H', and if possible, output the colored string.

Here's an explanation of the code:

Input:

The code takes two inputs:
n: an integer representing the length of the string s.
s: a string of length n consisting of characters 'H' and '.'.

Initialize a Flag:
bool possible is initialized to true. This flag will be used to check if it's possible to color the cells.

Check Possibility:
The code iterates through each character of the string s.
If a character 'H' is found, it checks if the next character (if exists) is also 'H'.
If two consecutive 'H' characters are found, it sets possible to false.

Output Result:
If it's possible to color the cells, it outputs "YES" and replaces all '.' characters in the string with 'B'.
If not possible, it outputs "NO".


Algorithm:

1. Iterate through each character of the string.
2. If a character 'H' is found, check if the next character is also 'H'.
3. If two consecutive 'H' characters are found, set possible to false.
4. After the iteration, if possible is true, output "YES" and replace all '.' characters with 'B'.
5. If possible is false, output "NO".


*/

//solution 
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool possible = true;
    for(int i=0; i<n; i++){
        if(s[i]=='H'){
            if(i+1<n && s[i+1]=='H') possible = false;
        }
    }
    if(possible){
        cout<<"YES"<<"\n";
        for(auto &ch: s){
            if(ch == '.'){
                ch = 'B';
            }
        }
        cout<<s<<"\n";
    }else cout<<"NO"<<"\n";

    return 0;
}

