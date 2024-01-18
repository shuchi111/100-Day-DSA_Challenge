// Climbing Stairs

/*

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Algorithm-
1. If n is less than or equal to 2, return n.
2. Initialize s0 to 0, s1 to 2, and s2 to 1.
3. For i from 2 to n-1, repeat steps 4-6.
4. Set s0 to s1 + s2.
5. Set s2 to s1.
6. Set s1 to s0.
7. Return s0.

The approach used in this implementation is based on dynamic programming.

 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int s0 = 0, s1 = 2, s2 = 1;
        for (int i = 2; i < n; ++i) {
            s0 = s1 + s2;
            s2 = s1;
            s1 = s0;
        }
        return s0;
    }
};
