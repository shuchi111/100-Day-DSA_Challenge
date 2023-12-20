//question -3 
 /*
 
 1
 12
 123
 1234
 12345
 
 */




#include<bits/stdc++.h>
using namespace std;
void print3(int n){
	for(int i =1;i<=n;i++) {
		for( int j =1; j<=i; j++){
			cout<<j<<" "; 
		}
		cout<<endl;
	}
}
	
	int main(){
		int n; //n=5
		cin>>n; //use this for user input otherwise ignore it
		print3(n);	
	}

	
	