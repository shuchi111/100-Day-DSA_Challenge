// 446. Arithmetic Slices II - Subsequence
/*

Example
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

Algorithm:

1. Initialization:
Initialize a 2D DP array (dp) to store the count of arithmetic slices ending at each pair of indices.
Create a map (map) to store the indices of each element in the input array.

2. Populating the Index Map:
Loop through the elements of the array, storing their indices in the map.

3. Dynamic Programming:
Iterate through pairs of indices (i and j).
Calculate a hypothetical missing element a in the arithmetic sequence using the formula 2 * nums[i] - nums[j].
If a exists in the map, update the DP array by adding the count of slices ending at indices less than i.

4. Result Calculation:
Accumulate the total count of arithmetic slices in the variable sum based on the DP array.

5. Final Result:
The variable sum represents the total number of arithmetic slices in the array.

Key Points:
Dynamic programming is used to keep track of valid arithmetic slices.
The map is used to efficiently find the indices of elements in the array.
The algorithm iterates through pairs of indices and updates the count based on the existence of a hypothetical missing element in the arithmetic sequence.

*/

//Solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<long, vector<int>> map;

        for (int i = 0; i < n; i++) {
            long temp = nums[i];
            if (!map.count(temp)) {
                map[temp] = vector<int>();
            }
            map[temp].push_back(i);
        }

        int sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long a = 2L * nums[i] - nums[j];
                if (map.count(a)) {
                    for (int k : map[a]) {
                        if (k < i) {
                            dp[i][j] += dp[k][i] + 1;
                        } else {
                            break;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
