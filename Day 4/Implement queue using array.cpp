// Implement Queue using array

/*

Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation:
In the first test case for query 
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3 



Approach -
Algorithm:
Push Operation (push):

1. Accept an integer x as a parameter.
2. Assign the value x to the array at the position rear.
3. Increment the rear index.

Pop Operation (pop):
1. Check if rear is equal to front. If true, return -1 (empty queue).
2. Otherwise:
Assign the value at the front index to a variable x.
Increment the front index.
3. Return the value x

*/

//Solution
//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    // Assign the value x to the array at the position rear.
    arr[rear] = x;
    // Increment the rear index.
    rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    // Check if rear is equal to front. If true, return -1 (empty queue).
    if (rear == front)
        return -1;
    else {
        // Assign the value at the front index to a variable x.
        int x = arr[front];
        // Increment the front index.
        front++;
        // Return the value x.
        return x;
    }
}

