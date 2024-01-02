// leetcode 75 Q12 - container with most water
/*

Approach:

The given algorithm aims to find the maximum area between two lines represented by the height vector. It utilizes a two-pointer approach, with pointers i and j initialized at the beginning and end of the vector. The algorithm iteratively adjusts the pointers to maximize the area between the lines.

1. Initialize pointers i and j to the beginning and end of the height vector, and initialize maxx to 0.
2. Iterate while i < j:
Calculate the area between lines represented by height[i] and height[j] using the formula (j - i) * min(height[i], height[j]).
Update maxx to be the maximum of the current maxx and the calculated area.
Move the pointer with the smaller height towards the center (increment i if height[i] < height[j], otherwise decrement j).
3. Return the maximum area, maxx.

Algorithm: maxArea(height)
1. Initialize i to 0, j to height.size() - 1, and maxx to 0.

2. Iterate while i < j:
Calculate the area between lines represented by height[i] and height[j].
Update maxx with the maximum of the current maxx and the calculated area.
Move the pointer with the smaller height towards the center (increment i if height[i] < height[j], otherwise decrement j).
3. Return the maximum area, maxx.
The algorithm uses the two-pointer approach to efficiently find the maximum area by continually adjusting the pointers towards the center based on the height of the lines at those positions.








*/

// Solution

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxx=0;
        while(i<j){
            int area=(j-i)*min(height[i],height[j]);
            maxx=max(maxx,area);
            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return maxx;
    }
};