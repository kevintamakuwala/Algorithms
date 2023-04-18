/*
    Problem Link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

    Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
    The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate 
    to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
*/

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       Node *temp=head,*temp2=head;
       int zero=0,one=0,two=0;
       
       while(temp)
       {
           if(temp->data==0)
           zero++;
           if(temp->data==1)
           one++;
           if(temp->data==2)
           two++;
           
           temp=temp->next;
       }
       while(temp2)
       {
           if(zero)
           {
               temp2->data=0;
               zero--;
           }
           else if(one)
           {
               temp2->data=1;
               one--;
           }
          else if(two)
           {
               temp2->data=2;
               two--;
           }
           temp2=temp2->next;
       }
       return head;
    }
};