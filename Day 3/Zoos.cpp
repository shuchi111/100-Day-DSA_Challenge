// Hackerearth Q4

/*

Zoos

Problem
You are required to enter a word that consists of x and y
 that denote the number of Zs and Os respectively. The input word is considered similar to word zoo if 2 Xx = y.
.

Determine if the entered word is similar to word zoo.
For example, words such as zzoooo and zzzoooooo are similar to word zoo but not the words such as zzooo and zzzooooo



Algorithmic Explanation:
1. Input:
Read a string from the user.

2. Count 'z' and 'o':
Initialize counters for 'z' (z) and 'o' (o) to zero.
Iterate through each character in the string.
If the character is 'z', increment the 'z' counter; otherwise, increment the 'o' counter.
Continue this process until the end of the string is reached.

3. Check the Condition:
Check if the count of 'o' is twice the count of 'z'.

4. Output:
If the condition is true, print "Yes"; otherwise, print "No".

*/


//Solution 
#include <iostream>
using namespace std;

int main() {
    int n = 0, o = 0, z = 0, i = 0;
    char s[20];

    cin >> s;
    while (s[i] != '\0') {
        if (s[i] == 'z') {
            z++;
        } else {
            o++;
        }
        i++;
    }

    if (o == z * 2) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
