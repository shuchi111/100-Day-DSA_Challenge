//Question 4
/*

1
22
333
4444
55555

I - Row = 5
II - Connect row to column  with any relation 
In every row we are printing row no. 
In 1 row = 1
In 2nd row = 2 , 2 times
*/ 

#include<bits/stdc++.h>
using namespace std;
void print4(int n){
	for(int i =1;i<=n;i++) {
		for( int j =1; j<=i; j++){
			cout<<i<<" "; 
		}
		cout<<endl;
	}
}
	
	int main(){
		int n; //n=5
		cin>>n; //use this for user input otherwise ignore it
		print4(n);	
	}