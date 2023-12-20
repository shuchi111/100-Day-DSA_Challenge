// Question 6
/*
12345
1234
123
12
1

Row = 5
base case for inner loop = n-i+1
*/

#include<bits/stdc++.h>
using namespace std;
void print6(int n){
	for(int i =1;i<=n;i++) {
		for( int j =1; j<=n-i+1; j++){
			cout<<j<<" ";  //print column
		}
		cout<<endl;
	}
}
	
	int main(){
		int n = 5;
		print6(n);	
	}
