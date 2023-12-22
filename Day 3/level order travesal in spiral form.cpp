// Level order traversal in spiral

/*
Algorithm:

1. Initialization:
Create an empty vector v to store the result.
If the input tree is empty, return an empty vector.

2. Breadth-First Traversal:
Use a queue to perform a level order traversal of the binary tree.
For each level, maintain a vector vs to store the values of nodes at that level.
Process each node at the current level, enqueue its left and right children if they exist, and add its value to vs.

3.Spiral Order Insertion:
Depending on whether the current level is even or odd:
If even, add the values from vs to the result vector in reverse order.
If odd, add the values from vs to the result vector in normal order.
4. Return Result:

Return the final result vector.

*/

//Solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int>v;
    if(root==NULL) return v;
    queue<Node*>q;
    q.push(root);
    int val=0;
    while(!q.empty()){
        int sz=q.size();
        vector<int>vs;
        for(int i=0; i<sz; i++){
            Node *node=q.front();
            q.pop();
            vs.push_back(node->data);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);            
        }
        if(val%2==0){
            for(int i=vs.size()-1; i>=0; i--){
                v.push_back(vs[i]);
            }
        }else{
            for(int i=0; i<vs.size(); i++){
                v.push_back(vs[i]);
            }            
        }
        val++;
    }
    return v;
}


        
                
          


