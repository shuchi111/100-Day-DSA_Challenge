#include<bits/stdc++.h>
using namespace std;


/*1. void function - it will not return nothing

Void Functions:
- A function declared with a return type of void means that
 it does not return any value.
- Void functions are used when the function is designed to perform a task without producing a result that needs to be used by the calling code.

*/
void print(){
	cout<<"Shuchi";
	
}

/*2. int - it will return 
Int Functions:

- A function declared with a return type of int means that 
it returns an integer value.
- Int functions are used when the result of 
the function is a numerical value that can be used by the calling code.


*/
int sum( int a, int b){
	return a+b;
	
}
int main(){
	print();
	int s = sum( 1, 5);
	cout<<s;
	//print 6
	return 0;
}
