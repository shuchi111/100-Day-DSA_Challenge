//hackerearth - Basic Q1
/*
Algorithm breakdown:

1. Declare variables: long num, input, max = 0, count = 0; declares variables for the number of inputs, the current input, the maximum frequency, and the count of numbers with the maximum frequency.

2. Read the number of inputs: cin >> num; reads the number of inputs from the standard input.

3. Create a map: map<long, long> fav; creates a map to store the frequency of each input number.

4. Update frequency in the map: The first loop (for (int i = 0; i < num; i++)) reads input numbers and updates their frequency in the map.

5. Find maximum frequency and count occurrences: The second loop (for (auto k : fav)) iterates through the map to find the maximum frequency and count the occurrences of numbers with the maximum frequency.

6. Display the count: cout << count << endl; prints the count of numbers with the maximum frequency.

7. End the program: return 0;


*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // Step 1: Declare variables
    long num, input, maxCount = 0, totalCount = 0;

    // Step 2: Read the total number of inputs
    cin >> num;

    // Step 3: Create a map to store the frequency of each input number
    map<long, long> fav;

    // Step 4: Read the input numbers and update the frequency map
    for (int i = 0; i < num; i++) {
        cin >> input;
        fav[input]++;
    }

    // Step 5: Iterate through the frequency map to find the most frequently occurring number(s)
    for (auto pair : fav) {
        if (maxCount < pair.second) {
            // If a new maximum frequency is found, update maxCount and reset totalCount
            maxCount = pair.second;
            totalCount = 1;
        } else if (maxCount == pair.second) {
            // If the frequency is equal to the current maximum, increment totalCount
            totalCount++;
        }
    }

    // Step 6: Display the count of the most frequently occurring number(s)
    cout << totalCount << endl;

    // Step 7: End the program
    return 0;
}


