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