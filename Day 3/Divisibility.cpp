// Divisibility - Hackerearth Q5
/*

Problem
You are provided an array A
 of size N that contains non-negative integers. Your task is to determine whether the number that is formed by selecting the last digit of all the N numbers is divisible by 
10 .


Input 
5
85 25 65 21 84

Output No

Approach

Algorithmic Explanation:
1. Input:
Read an integer n representing the size of the array.
2. Array Input:
Declare an array a of size n.
Input n elements into the array.
3. Extract Last Digit:
Loop through each element of the array.
For each element, find the remainder when divided by 10 (a[i] % 10), effectively extracting the last digit.
Update the variable rem with the last digit of the last array element.

4. Check Condition:
Check if the last digit (rem % 10) of the last array element is equal to 0.

5. Output:
If the condition is true, print "Yes"; otherwise, print "No".

*/

//Solution
#include <iostream>
using namespace std;
int main() {

	int n , rem = 0;
	cin>>n;
	int a[n];

	for( int i =0; i<n; i++){
		cin>>a[i];
	}
	for( int i =0; i<n; i++){
		rem = a[i]%10;
	}
	if(rem%10==0){
		cout<<"Yes"<<endl;
	}
	else
	cout<<"No"<<endl;
	}