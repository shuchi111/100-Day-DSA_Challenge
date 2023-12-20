//Question 1 ( Rectangular star Pattern )- 1st method
/*

***
***
***

*/

#include<bits/stdc++.h>
using namespace std;

void print1(){
	for(int i =0;i<4;i++) {
		
		for ( int j =0; j<4; j++){
			cout<<"*";
		}
		cout<<endl;
		//for next line after printing 4 star in a row
	}
}
int main(){
	print1();
    
}



//for given input by user - 2nd method

/*
void print1(int n ){
	for( int i =0; i<n; i++){
		for( int j =0; j<n; j++){
			cout<<"*";
			
		}
		cout<<endl;
		
	}
}

int main(){
	int n;
	cin>>n;
	print1(n);
}
*/


//similar problem try on online compiler- codingninjas
/*
N - forest

Problem statement 
Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled
with +.

For every value of ‘N’, help sam to print the corresponding N-dimensional forest.

Example:

Input: ‘N' = 3

Output:
* * *
* * *
* * *



Solution - for this just write second method and give space in printing star

for( int i =0; i<n; i++){
		for( int j =0; j<n; j++){
			cout<<"*  ";
		//add here space after star
			
		}
		cout<<endl;
		
	}
	
	
*/
