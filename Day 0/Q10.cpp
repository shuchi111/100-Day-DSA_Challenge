// Question 10
/*
Rule -4

Observe symmetry
logic -
outer loop rows = 9
2*n-1

Row 1 to 5 = Symmetry
from row row 6 onwards break symmetry

6- 4 star
7- 3 star
8- 2 star
9 - 1 star


( 2n -i ) = 2 * total no of rows - row no

*/
#include<bits/stdc++.h>
using namespace std;
void print10(int n){
	for(int i =1;i<=2*n-1;i++) { //outer loop
	int stars = i; // star = no of rows 
	if( i>n) stars = 2*n-i;
		for( int j =1; j<=stars; j++){
		cout<< " *";
		}
				
		cout<<endl;
	}
}	
	int main(){
		int n=5; 
		print10(n);
		return 0;	
	}
	