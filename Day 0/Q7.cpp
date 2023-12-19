// Question 7


/*
Medium level

A pyramid

        * 
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

Row = 5
Column = 9

[Space, star , space] = 3 different inner loop for each
pattern = 
4, 1, 4
3, 3, 3
2, 5, 2
1, 7, 1
0, 9, 0

n-i-1 = space
2*i+1 = star


*/

#include<bits/stdc++.h>
using namespace std;
void print7(int n){
	for(int i =0;i<n;i++) {
		//space
		for( int j =0; j<n-i-1; j++){
		cout<< " ";
		}
		//star
		for ( int j =0; j<2*i+1; j++){
			cout<<"*";
		}
		//space
		for( int j = 0; j<n-i-1; j++){
			cout<< " ";
		}
		cout<<endl;
	}
}
	
	int main(){
		int n=5; //n=5
		print7(n);
		return 0;	
	}
	
	
	