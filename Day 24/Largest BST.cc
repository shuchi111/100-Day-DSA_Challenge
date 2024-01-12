/*

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.


Algorithm

1. Initialize variables maxval, minval, isBST, and size.
2. Define a recursive function solve(root):
If root is NULL, return {INT_MIN, INT_MAX, true, 0}.
Recursively process the left subtree using solve.
Recursively process the right subtree using solve.
Update maxval, minval, size, and isBST based on the information from the left and right subtrees.
If the subtree is a valid BST, update the global maximum size maxans.
Return the information about the current subtree.
3. In the largestBst(root) function:
Initialize maxans to 0.
Call solve(root) to process the entire tree.
Return the final maximum size maxans as the result.
*/
//solution
//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


    /*You are required to complete this method */
    class Solution{
    public:
    
    int maxval;
    int minval;
    bool isBST;
    int size;
    
    Solution solve(Node* root, int& maxans){

        if(root == NULL)
            return {INT_MIN, INT_MAX, true, 0};
        
        Solution left = solve(root->left, maxans);
        Solution right = solve(root->right, maxans);
    
        Solution curr;
        curr.maxval = max(root->data, right.maxval);
        curr.minval = min(root->data, left.minval);
        curr.size = left.size + right.size + 1;
    
        if(left.isBST && right.isBST && 
            (root->data < right.minval && root->data > left.maxval)) 
            curr.isBST = true;
        
        else 
            curr.isBST = false;
    
        if(curr.isBST)
            maxans = max(maxans, curr.size);
        
        return curr;
    
    }
    
    int largestBst(Node *root)
    {
        int maxans = 0;
        Solution ans = solve(root, maxans);
        return maxans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends
