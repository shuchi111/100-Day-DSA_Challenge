//Question 1
#include<bits/stdc++.h>
using namespace std;
/*
void print1(){
	for(int i =0;i<4;i++) {
		
		for ( int j =0; j<4; j++){
			cout<<"*";
		}
		cout<<endl;
		//for next line aftfer printing 4 star in a row
	}
}
int main(){
	print1();
    
}

*/

//for given input by user

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

