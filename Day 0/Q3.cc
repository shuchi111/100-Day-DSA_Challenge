#include<bits/stdc++.h>
using namespace std;


void print2(int n){
	for(int i =0;i<n;i++) {
		for( int j =0; j<=i; j++){
			cout<<"*"; //make sure in onlinne compiler use space after star 
			
		}
		cout<<endl;
	}
}
	
	int main(){
		int n; //we can write here value of n if we don't need input from user
		cin>>n; //for user input 
		print2(n);	
	}