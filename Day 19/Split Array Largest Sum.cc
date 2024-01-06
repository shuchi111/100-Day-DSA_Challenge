//Split Array Largest Sum

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    
    int splitArray(int arr[] ,int N, int K) {
        long long l = 1,r = 1e9;
        long long ans = r;
        function<bool(int mid)> possible = [&](int mid)->bool{
            int cnt = 1;
            int sum = 0;
            for(int i = 0;i<N;i++){
                if(arr[i]>mid) return false;
                sum+=arr[i];
                if(sum>mid){
                    cnt++;
                    sum = arr[i];
                }
            }
            return cnt<=K;
        };
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(possible(mid)){
                ans = mid;
                r= mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
