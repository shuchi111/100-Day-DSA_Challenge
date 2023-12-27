// Flood fill Algorithm

/*

Use dfs

Example -

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.


Algorithm:

1. Function merge:
This is a recursive function that performs the Flood Fill.
It checks if the current pixel is within the image boundaries, not visited, and has the same color as the starting pixel.
If conditions are met, it updates the pixel color, marks it as visited, and calls itself recursively for the neighboring pixels.

2. Function floodFill:
This function initializes a 2D visited array with the same dimensions as the image to keep track of visited pixels.
It calls the merge function with the starting pixel (sr, sc), the current color of that pixel (image[sr][sc]), and the new color to be filled.
Returns the modified image.

*/

//Solution
class Solution {
public:
    // Function to perform Flood Fill recursively
    void merge(vector<vector<int>> &img, int r, int c, int same, int color, vector<vector<int>>& visited) {
        // Check if the current pixel is within bounds, not visited, and has the same color
        if (r >= 0 and r < img.size() and c >= 0 and c < img[0].size() and !visited[r][c] and img[r][c] == same) {
            // Update the color of the current pixel
            img[r][c] = color;
            // Mark the current pixel as visited
            visited[r][c] = 1;
            
            // Recursive calls for neighboring pixels
            merge(img, r - 1, c, same, color, visited);
            merge(img, r + 1, c, same, color, visited);
            merge(img, r, c - 1, same, color, visited);
            merge(img, r, c + 1, same, color, visited);
        }
    }

    // Function to perform Flood Fill on the image
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Create a 2D array to keep track of visited pixels
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        
        // Call the merge function starting from the specified pixel
        merge(image, sr, sc, image[sr][sc], newColor, visited);
        
        // Return the modified image
        return image;
    }
};

