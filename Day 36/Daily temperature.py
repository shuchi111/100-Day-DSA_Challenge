# Daily temperature
"""


Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Explanation of the algorithm:

1. Initialize an array ans to store the result, where ans[i] will represent the number of days one has to wait until a warmer temperature is encountered for the day i.
2. Use a stack (stack) to keep track of temperatures and their corresponding indices.
3. Iterate through the temperatures and their indices using the enumerate function.
4. While the stack is not empty and the current temperature is greater than the temperature at the top of the stack, update the result for the corresponding index on the stack by calculating the difference between the current index i and the index at the top of the stack.
5. Push the current temperature and its index onto the stack.
6. After the iteration is complete, the ans array will contain the solution for each day, representing the number of days one has to wait until a warmer temperature is encountered.


"""
#code
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # Initialize an array to store the result, initialized with zeros.
        ans = [0] * len(temperatures)
        
        # Stack to keep track of temperatures and their corresponding indices.
        stack = []

        # Iterate through the temperatures and their indices.
        for i, t in enumerate(temperatures):
            # While the stack is not empty and the current temperature is greater
            # than the temperature at the top of the stack, update the result.
            while stack and t > stack[-1][0]:
                temp_t, temp_i = stack.pop()
                ans[temp_i] = i - temp_i
            # Push the current temperature and its index onto the stack.
            stack.append([t, i])

        # Return the resulting array.
        return ans
