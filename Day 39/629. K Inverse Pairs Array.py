#629. K Inverse Pairs Array


'''Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.



Algorithm:

1. Initialize an array dp of size k+1 with the first element set to 1 and the rest to 0. Also, set the variable mod to 1000000007.

2. Iterate i over the range n:

Initialize an empty list tmp to store the updated values for dp.
Initialize a variable sm to 0.
Iterate j over the range k + 1:
Increment sm by dp[j].
If j-i is greater than or equal to 1, decrement sm by dp[j-i-1].
Take the modulo of sm with mod.
Append the updated value of sm to the list tmp.
Update the array dp with the values in the list tmp.
3. Return the value at index k in the array dp.

'''

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        dp, mod = [1]+[0] * k, 1000000007
        
        for i in range(n):
            tmp, sm = [], 0
            for j in range(k + 1):
                sm+= dp[j]
                if j-i >= 1: sm-= dp[j-i-1]
                sm%= mod
                tmp.append(sm)
            dp = tmp
            #print(dp)       # <-- uncomment this line to get a sense of dp from the print output
			                 #     try n = 6, k = 4; your answer should be 49.
        return dp[k]     
