// Count BST nodes that lie in a given range
/*
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range


Approach:
 To count the number of nodes in a Binary Search Tree (BST) that lie in the given range, we can perform an in-order traversal of the tree and count the nodes whose values fall within the specified range.

1. Start from the root and recursively traverse the left subtree.
2. If the current node's value is within the given range [l, h], increment the count.
3. Recursively traverse the right subtree.
4. Return the total count.

Algorithm:

1. If the root is NULL, return 0.
2. Initialize two variables left and right with the results of recursive calls on the left and right subtrees, respectively.
3. If the root's data is within the range [l, h], increment the count by 1.
4. Return the sum of left, right, and 1.

*/

//solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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
//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if(root == NULL)return 0;
      int left = getCount(root->left,l,h);
      int right = getCount(root->right,l,h);
      if(root->data >= l and root->data <= h)
      return left+right+1;
      return left+right;
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int l, r;
		cin >> l >> r;
		Solution ob;
		Node* root = buildTree(s);
		cout << ob.getCount(root, l, r) << endl;
		
	}
	return 1;
}

// } Driver Code Ends

