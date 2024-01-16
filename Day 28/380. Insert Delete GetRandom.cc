// 380. Insert Delete GetRandom O(1)
/*

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]



Approach 
Algorithm for RandomizedSet Class:

Data Members:
- unordered_map<int, int> pos: A map to store the position of each element in 'values'.
- vector<int> values: A vector to store the actual elements.

Constructor:
1. Initialize the RandomizedSet object.

Insert Operation (bool insert(int val)):
1. Check if 'val' is already present in the 'pos' map.
   a. If found, return false (element already exists).
   b. If not found, proceed to the next step.
2. Add 'val' to the end of the 'values' vector.
3. Update the position of 'val' in the 'pos' map to be the current size of 'values'.
4. Return true (element inserted successfully).

Remove Operation (bool remove(int val)):
1. Check if 'val' is present in the 'pos' map.
   a. If not found, return false (element doesn't exist).
   b. If found, proceed to the next step.
2. Get the position (p1) of 'val' in the 'values' vector.
3. Get the position (p2) of the last element in the 'values' vector.
4. Swap the elements at positions p1 and p2 in the 'values' vector.
5. Update the position of the element at p1 in the 'pos' map to be p1.
6. Remove the last element from the 'values' vector.
7. Erase the entry for 'val' from the 'pos' map.
8. Return true (element removed successfully).

Get Random Element Operation (int getRandom()):
1. Generate a random index 'randomIndex' in the range [0, size of 'values') using rand() % values.size().
2. Return the element at 'randomIndex' in the 'values' vector.




  Explanation:

1. Insert Operation:
Check if the element already exists in the set (pos map).
If not, add the element to the end of the values vector, update its position in the pos map, and return true.

2. Remove Operation:
Check if the element exists in the set (pos map).
If yes, swap the element to be removed with the last element in values, update the positions in pos accordingly, and return true.

3. Get Random Element Operation:
Generate a random index within the range of the current size of values and return the element at that index.


*/

//Solution 
class RandomizedSet {
public:
    // Data members
    unordered_map<int, int> pos;  // Map to store the position of each element in 'values'
    vector<int> values;           // Vector to store the actual elements

    // Constructor
    RandomizedSet() {
        // Initialization
    }
    
    // Insert operation
    bool insert(int val) {
        if (pos.find(val) != pos.end())
            return false; // Element already exists

        // Add the element to the end of 'values'
        pos[val] = values.size(); // Update its position in 'pos'
        values.push_back(val);

        return true;
    }
    
    // Remove operation
    bool remove(int val) {
        if (pos.find(val) == pos.end())
            return false; // Element doesn't exist

        // Swap the element to be removed with the last element in 'values'
        int p1 = pos[val];
        int p2 = values.size() - 1;
        swap(values[p1], values[p2]);

        // Update the position of the swapped element in 'pos'
        pos[values[p1]] = p1;

        // Remove the last element from 'values'
        values.pop_back();

        // Remove the element from 'pos'
        pos.erase(val);

        return true;
    }
    
    // Get a random element operation
    int getRandom() {
        return values[rand() % values.size()]; // Generate a random index and return the corresponding element
    }
};



 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

