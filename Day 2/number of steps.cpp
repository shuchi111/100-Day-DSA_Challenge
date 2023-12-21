// Hackerearth Q3
// No. of steps 
/*
Sample input

25 64 3

Sample output

-1




Approach-
1. Read the value of n.
2. Create two vectors A and B to store the input values.
3. Read n elements for vector A.
4.  Read n elements for vector B.
5. Find the minimum element in vector A using the min_element function and store it in minIt.
6. Initialize minValue with the value pointed by minIt.
7. Initialize i to 0 and steps to 0.
8. Iterate over elements of vector A:
While the current element A[i] is greater than minValue:
Subtract B[i] from A[i].
Increment steps.
If A[i] becomes less than minValue:
Update minValue with the new value of A[i].
If i is at the last index (i == n-1), set steps to -1 to indicate that it's not possible to make all elements equal.
If A[i] becomes negative, set steps to -1 to indicate that it's not possible to make all elements equal.
Otherwise, increment i.
9. Print the value of steps.


*/


//solution

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A, B;
    
    // Read elements for vector A
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }

    // Read elements for vector B
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    // Find the minimum element in vector A
    auto minIt = min_element(A.begin(), A.end());
    int minValue = *minIt;
    
    int i = 0, steps = 0;

    // Iterate over elements of vector A
    while(i < n){
        // While current element A[i] is greater than minValue
        while(A[i] > minValue){
            A[i] -= B[i];
            ++steps;
        }

        // If A[i] becomes less than minValue
        if(A[i] < minValue){
            minValue = A[i];

            // If i is at the last index, set steps to -1
            if(i == n-1){
                steps = -1;
                break;
            }
        }
        // If A[i] becomes negative, set steps to -1
        else if(A[i] < 0){
            steps = -1;
            break;
        }
        else{
            // Otherwise, increment i
            i++;
        }
    }

    // Print the value of steps
    cout << steps << "\n";

    return 0;
}

