/*
    Problem Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

    Given an unsorted linked list of N nodes. 
    The task is to remove duplicate elements from this unsorted Linked List.
    When a value appears in multiple nodes, the node which appeared first should be kept, 
    all others duplicates are to be removed.

*/

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int,int>mp;
        
        Node *curr=head,*prev=head;
        mp[curr->data]++;
        curr=curr->next;
        
        while(curr!=NULL)
        {
            if(mp[curr->data]==0)
            {
                mp[curr->data]++;
                curr=curr->next;
                prev=prev->next;
            }
            else
            {
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
        }
        return head;
    }
};