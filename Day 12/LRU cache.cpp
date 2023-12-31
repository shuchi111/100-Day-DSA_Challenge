//Day 12 LRU cache
/*

Example 1:

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding
to Key 1, ie 2.





Your Task:
You don't need to read input or print anything. Complete the constructor and get(), and set() methods of the class LRUcache. 



Algorithm 

LRU Cache Implementation:

Algorithm:

1. Initialization:
Initialize the LRU cache with a specified capacity.
Create a doubly linked list to maintain the order of accessed elements.
Use a hash map to store the mapping of keys to corresponding nodes in the linked list.

2. Insert Operation (insert(node* temp)):
Insert the given node at the beginning of the linked list to indicate the most recently used element.
Update the hash map with the new mapping.

3. Remove Operation (rem(node* temp)):
Remove the given node from the linked list, effectively excluding it from the cache.

4. Get Operation (GET(int key)):
If the key is not present in the cache, return -1.
If the key is present, retrieve the corresponding node and move it to the beginning of the linked list (indicating recent use).
Return the value associated with the key.

5. Set Operation (SET(int key, int value)):\
If the key is already present in the cache, update the corresponding node's value, remove it from the linked list, and insert it at the beginning.
If the key is not present:
If the cache size is less than the capacity, insert a new node at the beginning.
If the cache size is full, remove the least recently used node (from the end of the linked list) and insert the new node.

*/
//Solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    
    struct node
    {
        int key,val;
        node* prev;
        node* next;
        
        node(int k,int v)
        {
           key=k;
           val=v;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int capacity;
    unordered_map<int,node*> mp;

    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
        
    }
    
    //evert time insets the node at the begining
    void insert(node* temp)
    {
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        
        mp[temp->key]=temp;
    }
    
    //remove the given node from the links of linked list 
    void rem(node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)==mp.end())
        return -1;
        
        node* cur=mp[key];
        rem(cur);
        insert(cur);
        return cur->val;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        //If key is already present in the cache
        if(mp.find(key)!=mp.end())
        {
            node* cur=mp[key];
            cur->val=value;
            
            rem(cur);
            insert(cur);
            
        }
        //if key is not present and also the cache size is less than this capacity
        else if(mp.size()<capacity)
        {
            node* newnode=new node(key,value);
            insert(newnode);
        }
        //when cache size is full and need to insert new key
        else
        {
            //permanently remove the least used node
            node* cur=tail->prev;
            rem(cur);
            mp.erase(cur->key);
            delete cur;
            
            //insert the new node
            node* newnode=new node(key,value);
            insert(newnode);
            
            
        }
    }
};
 





 

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
