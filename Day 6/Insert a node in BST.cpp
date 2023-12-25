// Insert a node in a BST
/*

Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

Example 1:

Input:
     2
   /   \   
  1     3
K = 4
Output: 
1 2 3 4
Explanation: 
After inserting the node 4
Inorder traversal will be 1 2 3 4.


Approach-

1. Initialize Pointer:
Declare a double pointer (link_addr) and set it to the address of the root of the BST.

2. Search and Traverse:
Iterate through the BST until finding the node with the same key or reaching an empty spot.
Move the link_addr to the left or right child based on comparisons with the current node's data.

3. Insertion:
If the link_addr is pointing to an empty spot (nullptr), create a new node with the given key and link it to the current position.

4. Return Root:
Return the root of the BST (unchanged).

*/

//solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    Node* insert(Node* root, int key)
    {
        //pointer to link to be changed
        Node ** link_addr = &root;
        
        while(((*link_addr)!=nullptr)&&(((*link_addr)->data)!=key))
        {
            if(((*link_addr)->data)<key)
            {
                link_addr = &((*link_addr)->right);
            }
            else
            {
                link_addr = &((*link_addr)->left);
            }
        }
        
        if((*link_addr)==nullptr)
        {
            //same key not found, so can be inserted
            (*link_addr) = new Node(key);
        }
        return root;
        
    }

        
         

};


//{ Driver Code Starts.

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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution ob;
        ob.insert(root, k);
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}

// } Driver Code Ends
