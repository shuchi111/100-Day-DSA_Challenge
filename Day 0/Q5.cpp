// Question 5

/*

*****
****
***
**
*


1->5
2->4
3->3
4->2
5->1

connect relation = [ Total rows(n)  - row no+ 1 ] 
*/

#include<bits/stdc++.h>
using namespace std;
void print5(int n){
	for(int i =1;i<=n;i++) {
		for( int j =0; j<n-i+1; j++){
			cout<<"*"; 
		}
		cout<<endl;
	}
}
	
	int main(){
		int n; //n=5
		cin>>n; //use this for user input otherwise ignore it
		print5(n);	
	}