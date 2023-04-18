/*
    Problem Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
    
    Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
    (i) a next pointer to the next node,
    (ii) a bottom pointer to a linked list where this node is head.
    Each of the sub-linked-list is in sorted order.
    Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

    Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
    
*/

Node *merge(Node* root1,Node* root2)
{
    if(!root1)
    return root2;
    
    if(!root2) 
    return root1;
    
    Node* dummy=new Node(0);
    Node* temp;
    
    temp=dummy;
    
    while(root1 && root2)
    {
        if(root1->data < root2->data)
        {
            temp->bottom=root1;
            root1=root1->bottom;
        }
        else
        {
            temp->bottom=root2;
            root2=root2->bottom;
        }
        temp=temp->bottom;
    }
    
    while(root1)
    {
        temp->bottom=root1;
        root1=root1->bottom;
        temp=temp->bottom;
    }
    while(root2)
    {
        temp->bottom=root2;
        root2=root2->bottom;
        temp=temp->bottom;
    }
    return dummy->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node *flatten(Node *root)
{
	   Node* h1=root;
	   while(h1 && h1->next)
	   {
	       Node*temp=h1->next->next;
	       h1=merge(h1,h1->next);
	       h1->next=temp;
	   }
	   return h1;
}
