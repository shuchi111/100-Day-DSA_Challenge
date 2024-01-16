//Heap sort
/*


Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.



Heap Sort Algorithm:
1. Build Max-Heap: Start by building a max-heap from the given array. This is done by calling the buildHeap function. The buildHeap function iterates through the non-leaf nodes of the binary tree (from the last non-leaf node to the root) and calls heapify for each node. This ensures that the array satisfies the max-heap property, where the value of each node is greater than or equal to the values of its children.
2. Heapify: The heapify function is a crucial part of the algorithm. It is used to maintain the heap property during the construction of the heap and during the sorting process. The function takes three parameters - the array, the size of the heap (n), and the index (i) where the heap property might be violated.
Calculate the indices of the left and right children of the current node.
Find the largest among the current node, its left child, and its right child.
If the largest is not the current node, swap the current node with the largest child and recursively call heapify on the affected sub-tree.
3. Sort the Array: After building the max-heap, the array is in the form of a heap where the maximum element is at the root. The heapSort function repeatedly extracts the maximum element (root) by swapping it with the last element in the array. After each extraction, it calls heapify on the reduced heap (excluding the last element) to maintain the heap property. This process continues until the entire array is sorted.

*/
//solution
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int l = 2 * i + 1;
      int r = 2 * i + 2;
      int largest = i;
      
      if(l < n && arr[largest] < arr[l]) largest = l;
      if(r < n && arr[largest] < arr[r]) largest = r;
      
      if(largest != i) {
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        // Your Code Here
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        //code here
        for(int i = n - 1; i >= 0; i--)
        {
            swap(arr[0],arr[i]);
            heapify(arr, i, 0);
        }
    }
};
