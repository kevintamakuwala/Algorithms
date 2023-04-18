/*
    Problem Link: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

    Given a linked list of size N. The task is to complete the function countNodesinLoop() 
    that checks whether a given Linked List contains a loop or not and if the loop is present
    then return the count of nodes in a loop or else return 0.
    C is the position of the node to which the last node is connected. 
    If it is 0 then no loop.
*/

struct Node *detectloop(struct Node *head)
{
    struct Node *fast=head,*slow=head;
    
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        return slow;
        
        if(!fast)
        break;
    }
    return NULL;
    
}
struct Node *loopNode(struct Node *head)
{
    struct Node *slow=head,*temp=detectloop(head);
    
    if(temp==NULL)
    return NULL;
    
    while(slow!=temp)
    {
        slow=slow->next;
        temp=temp->next;
    }
    return slow;
    
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    struct Node *loopStarting=loopNode(head),*temp=loopStarting;
    int cnt=0;
    if(loopStarting==NULL)
    return 0;
    
    while(loopStarting !=temp->next)
    {
        cnt++;
        temp=temp->next;
    }
    return ++cnt;   
}