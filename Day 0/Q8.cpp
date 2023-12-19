// Question 8
/*

inversion order of Question 7


Space , star , space
0 , 9, 0
1 , 7, 1
2 , 5, 2
3, 3, 3
4 , 1, 4

2n -(2i + 1)

*/

#include<bits/stdc++.h>
using namespace std;
void print8(int n){
	for(int i =0;i<n;i++) {
		//space
		for( int j =0; j<i; j++){
		cout<< " ";
		}
		//star
		for ( int j =0; j<2*n - ( 2*i+1); j++){
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
		print8(n);
		return 0;	
	}
	
	