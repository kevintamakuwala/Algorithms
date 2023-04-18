/*
    Problem Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

    Given a singly linked list of size N. 
    The task is to left-shift the linked list by k nodes, where k is a given positive integer
    smaller than or equal to length of the linked list.

*/

class Solution
{
    public:
    int length(Node *head)
    {
        Node *temp=head;
       int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node* rotate(Node* head, int k)
    {
        if(head==NULL)
        return NULL;
        if(head->next==NULL || length(head)==k)
        return head;
        
        int cnt=0;
        Node *temp=head,*list2,*temp2;
        while(cnt<k-1)
        {
            cnt++;
            temp=temp->next;
        }
        list2=temp->next;
        temp->next=NULL;
        temp2=list2;
        while(temp2->next)
        {
            temp2=temp2->next;
        }
        temp2->next=head;
        return list2;
        
    }
};