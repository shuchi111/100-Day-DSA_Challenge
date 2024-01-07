//202. Happy Number
/*
Algorithm: isHappy(n)

 Input: A positive integer n.
 Output: True if n is a happy number, and False otherwise.

1. Define a helper function help(n):
Initialize a variable ans to 0.
While n is not zero:
Extract the last digit of n and square it.
Add the squared digit to ans.
Update n by removing its last digit.
Return the final value of ans.

2. Initialize two pointers slow and fast to the value of n.
3. Use Floyd's cycle-finding algorithm:
In a do-while loop:
Move the slow pointer one step at a time by calling help(slow).
Move the fast pointer two steps at a time by calling help(help(fast)).
Continue the loop until slow is equal to fast, indicating a cycle.

4. Check the result:
If the loop ends with slow equal to 1, return True (the number is a happy number).
Otherwise, return False (the number is not a happy number).



*/
//Solution
class Solution {
public:
    int help(int n) {
        int ans = 0;
        while (n) {
            int temp = n % 10;
            ans += (temp * temp);
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = help(slow);
            fast = help(help(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
