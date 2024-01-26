// fractional knapsack

/*

Example 1:

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000
Explanation:
Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total weight becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 


Algorithm:
1. Create an array of pairs containing the ratio of value to weight and the weight of each item.
2. Sort the array in descending order based on the ratios.
3. Initialize a variable sum to 0.
4. Iterate through the sorted array:
If the entire weight of the current item can be accommodated, add its value to sum and subtract its weight from the remaining capacity.
If not, add the value proportional to the remaining capacity.
5. Return sum as the maximum value.


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double sum=0;
        vector<pair<double,int>> v;
        for(int i=0;i<n;i++)
        {
           double ratio=double(arr[i].value)/double(arr[i].weight);
           v.push_back({ratio,arr[i].weight});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(W>0)
            {
              if(v[n-1-i].second<=W)
              {
                sum+=v[n-1-i].second*v[n-1-i].first;
                W-=v[n-1-i].second;
              }
              else
              {
                sum+=v[n-1-i].first*W;
                W=0;
              }
            }
            else break;
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
