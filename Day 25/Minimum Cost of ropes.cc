//Minimum Cost of ropes

/*
Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 5, 6}. Cost of
this operation 2+3 = 5. 
2) Now connect ropes of lengths 4 and 5.
Which makes the array {9, 6}. Cost of
this operation 4+5 = 9.
3) Finally connect the two ropes and all
ropes have connected. Cost of this 
operation 9+6 =15
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. 
Other ways of connecting ropes would always 
have same or more cost. For example, if we 
connect 4 and 6 first (we get three rope of 3,
2 and 10), then connect 10 and 3 (we get
two rope of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.



Approach:

To minimize the cost of connecting the ropes, we can use a priority queue (min heap). The idea is to always connect the two smallest ropes available at each step to minimize the total cost.

Algorithm:

1. Create a priority queue (min heap) and insert all the elements of the array into it.
2. While the priority queue has more than one element:
Extract the two smallest elements from the priority queue.
Combine these two elements by adding them.
Add the result back to the priority queue.
Update the total cost with the combined value.
3. Return the total cost.



*/
//solution
class Solution {
public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Insert all elements into the min heap
        for (long long i = 0; i < n; i++)
            pq.push(arr[i]);

        long long cost = 0;
        
        // Connect ropes until only one rope remains in the heap
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a + b;
            cost += sum;
            pq.push(sum);
        }

        return cost;
    }
};
