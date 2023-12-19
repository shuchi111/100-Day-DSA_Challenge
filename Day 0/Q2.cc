//Question 2

/*

*
**
***
****
*****


According to approach 
I- Row = 5
II - connect row to column
0th row - 1 star
1st row - 2 star
2nd row - 3rd star

*/

#include<bits/stdc++.h>
using namespace std;


void print2(int n){
	for(int i =0;i<n;i++) {
		for( int j =0; j<=i; j++){
			cout<<"*";
			
		}
		cout<<endl;
	}
}
	
	int main(){
		int n;
		cin>>n;
		print2(n);
		
		
	}
		
		
	