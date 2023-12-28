// Inverse of an array  - count inversion 
/*
Approach -

1. MergeAndCount Function:
Merge two sorted arrays (arr[left...mid-1] and arr[mid...right]) into a single sorted array.
While merging, count inversions by comparing elements from the left and right arrays.
Return the total count of inversions.

2. MergeSortAndCount Function:
Recursively divide the array into two halves and sort each half.
Count inversions during the merge step by calling MergeAndCount.
Return the total count of inversions.

3. inversionCount Function:
Initialize a temporary array temp.
Call MergeSortAndCount to perform the sorting and count inversions.
Return the total count of inversions.





*/

//Solution


class Solution{
public:
    long long int MergeAndCount(long long arr[], long long temp[], int left, int mid, int right) {
        int i = left;
        int j = mid; 
        int k = left; 
        long long int inversionCount = 0;
        while (i <= mid - 1 && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                 temp[k++] = arr[j++];
                inversionCount += (mid - i); 
            }
        }
        while (i <= mid - 1) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
        return inversionCount;
    }
    long long int MergeSortAndCount(long long arr[], long long temp[], int left, int right) {
        long long int inversionCount = 0;
        if (left < right) {
            int mid = (left + right) / 2;
            inversionCount += MergeSortAndCount(arr, temp, left, mid);
            inversionCount += MergeSortAndCount(arr, temp, mid + 1, right); 
            inversionCount += MergeAndCount(arr, temp, left, mid + 1, right); 
        }
        return inversionCount;
    }
    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return MergeSortAndCount(arr, temp, 0, N - 1);
    }
};

