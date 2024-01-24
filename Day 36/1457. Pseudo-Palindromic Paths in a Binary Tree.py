class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode], cnt = [0]*10) -> int:   
        # Base Case: If the current node is None, return 0
        if not root:
            return 0

        # Update Count: XOR the count of the current node's value
        cnt[root.val] ^= 1

        # Check Pseudo-Palindromic Path:
        # Condition is met if the current node has both left and right children
        # and the total count of odd occurrences in the path is less than 2.
        # OR the current node is a leaf node and the total count of odd occurrences is 0.
        ans = ((root.left == root.right and sum(cnt) < 2) + 
                self.pseudoPalindromicPaths(root.left, cnt) +
                self.pseudoPalindromicPaths(root.right, cnt))

        # Backtrack Count: XOR the count of the current node's value again
        cnt[root.val] ^= 1

        # Return Result: Sum of count obtained for the current path and counts from recursive calls
        return ans

"""
Algorithm:
Function pseudoPalindromicPaths(root, cnt):
    If root is None:
        Return 0

    XOR the count of the current node's value in cnt

    Check if the current path can potentially form a palindrome:
        If the current node has both left and right children and the total count of odd occurrences in the path is less than 2
        OR the current node is a leaf node and the total count of odd occurrences is 0.

    Recursively call pseudoPalindromicPaths for the left and right children of the current node, passing along the updated cnt array.

    Backtrack: XOR the count of the current node's value again

    Return the sum of the count obtained for the current path and the counts obtained from the recursive calls.

"""
