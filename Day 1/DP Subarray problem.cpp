// Subarray with given sum 
// Using Dynamic programming

/*

We can use dynamic programming to find the subarray with the given sum.
 The basic idea is to iterate through the array, keeping track of the current sum and storing the difference between the current sum and the given sum in a hash table. If the difference is seen again later in the array, then we know that the subarray with the given sum exists and we can return it. This approach is efficient in terms of time and space, but it may not be suitable if the array is very large and 
the hash table becomes too large to fit in memory.

Algorithm:

1. Initialize an empty hash table and a variable curr_sum to 0.
2. Iterate through the array, keeping track of the current element in a variable i.
3. Add i to curr_sum and check if curr_sum – sum is in the hash table. If it is, then return the subarray from the index stored in the hash table to i.
4. If curr_sum – sum is not in the hash table, add an entry to the hash table with the key curr_sum and the value i.
5. If you reach the end of the array and no subarray with the given sum is found, return an empty array.


*/

#include <iostream>
#include <unordered_map>
#include <vector>
 
std::vector<int>
find_subarray_with_given_sum(const std::vector<int>& arr,
                             int sum)
{
    std::unordered_map<int, int> map;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];
        if (map.count(curr_sum - sum)) {
            return std::vector<int>(
                arr.begin() + map[curr_sum - sum] + 1,
                arr.begin() + i + 1);
        }
        map[curr_sum] = i;
    }
    return {};
}
 
int main()
{
    std::vector<int> arr = { 15, 2, 4, 8, 9, 5, 10, 23 };
    std::vector<int> subarray
        = find_subarray_with_given_sum(arr, 23);
    if (subarray.empty()) {
        std::cout << "No subarray with given sum found"
                  << std::endl;
    }
    else {
        std::cout << "Subarray: [ ";
        for (int i : subarray) {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}