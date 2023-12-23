// leetcode Q4 - 605. Can place flowers

/*

Approach -
1. Iterate through each index of the flowerbed.
2. Check the conditions for planting a flower at the current index.
3. If conditions are met, plant a flower, decrement n, and skip the next index.
4. After each iteration, check if all required flowers have been planted.
5. If all flowers are planted, return true; otherwise, return false.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true



*/
//solution 
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                
                flowerbed[i] = 1;
                --n;
                
                if (n == 0) {
                    return true;
                }
                
                // Skip the next index since we have planted a flower there
                ++i;
            }
        }
        // Check if no more flowers need to be planted
        return n <= 0;
    }
};