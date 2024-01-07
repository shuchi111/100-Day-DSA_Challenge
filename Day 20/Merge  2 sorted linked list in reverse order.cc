//Merge 2 sorted linked list in reverse order
/*
Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.


Algorithm mergeResult(node1, node2):
    if node1 is NULL:
        return reverse(node2)
    if node2 is NULL:
        return reverse(node1)

    ans = NULL
    a = ans
    n1 = node1
    n2 = node2

    while n1 is not NULL and n2 is not NULL:
        if n1->data <= n2->data:
            if ans is NULL:
                ans = n1
                a = ans
            else:
                a->next = n1
                a = a->next
            n1 = n1->next
        else:
            if ans is NULL:
                ans = n2
                a = ans
            else:
                a->next = n2
                a = a->next
            n2 = n2->next

    if n1 is not NULL:
        a->next = n1
    else:
        a->next = n2

    return reverse(ans)




*/
// Solution
class Solution
{
    public:

    struct Node *rev(Node* ans)    {
        Node *p=NULL;
        Node *f=ans;
        Node *c=ans;
        while(c){
            f=c->next;
            c->next=p;
            p=c;
            c=f;
        }
        return p;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(node1==NULL) return rev(node2);
        if(node2==NULL) return rev(node1);
        Node* ans=NULL;
        Node* a=ans;
        Node* n1=node1;
        Node* n2=node2;
     
        while(n1!=NULL and n2!=NULL){
     
            if(n1->data<=n2->data){
                if(ans==NULL){
                    ans=n1;
                    a=ans;
                }
                else{
                    
                    a->next=n1;
                    a=a->next;
                }
                n1=n1->next;
            }
            else{
                if(ans==NULL){
                    ans=n2;
                    a=ans;
                }
                else{
                    a->next=n2;
                    a=a->next;
                }
                n2=n2->next;
            }
           
        }

        if(n1!=NULL){
            a->next=n1;
        }
        else{
            a->next=n2;
        }
        return rev(ans);
    }  
};
