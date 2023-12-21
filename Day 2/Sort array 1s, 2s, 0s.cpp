// Sort an array of 0s, 1s, 2s
/*
Dutch National Flag Algorithm:
The Dutch National Flag Algorithm is a sorting algorithm designed to segregate elements of an array into three distinct groups (commonly colors), maintaining the order of appearance. It is particularly useful for sorting arrays containing elements with three distinct values, such as 0, 1, and 2.

Algorithm (Three-Way Partitioning):
Initialize three pointers: low (points to the start of the array), mid (points to the current element being processed), and high (points to the end of the array).
Use a while loop to iterate until mid crosses high.
Check the value at the mid pointer:
If the value is 0, swap it with the element at the low pointer and increment both low and mid.
If the value is 1, it is already in the correct position; just increment mid.
If the value is 2, swap it with the element at the high pointer and decrement high.
After the loop, the array is partitioned into three sections: all 0s before low, all 1s between low and mid, and all 2s after high.



Problem -
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.




Algo
Algorithm:
1. Initialize three pointers: low (points to the start of the array), mid (points to the current element being processed), and high (points to the end of the array).
2. Use a while loop to iterate until mid crosses high.
Check the value at the mid pointer:
If the value is 0, swap it with the element at the low pointer, and increment both low and mid.
If the value is 1, it is already in the correct position; just increment mid.
If the value is 2, swap it with the element at the high pointer, and decrement high.
3. After the loop, the array is partitioned into three sections: all 0s before low, all 1s between low and mid, and all 2s after high.

*/

//solution 
class Solution
{
public:
    void sort012(int arr[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
