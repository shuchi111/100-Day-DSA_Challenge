//Array Pair Sum Divisibility Problem
/*

Example 1 :

Input : 
nums = [9, 5, 7, 3]
k = 6
Output: 
True
Explanation: 
{(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.


Algorithm:


*/
//solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

bool canPair(vector<int> nums, int k) {

        if(nums.size() & 1)
            return 0;
        if (k == 1) {
            return nums.size() >= 2;
        }

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num % k]++;
        }
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;
            if (num == 0) {
                if (count % 2 == 1) {
                    return false;
                }
            } else if (freq[k - num] != count) {
                return false;
            }
        }
        return true;

}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
