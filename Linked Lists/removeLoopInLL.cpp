/*
    Problem Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

    Given a linked list of N nodes such that it may contain a loop.
    A loop here means that the last node of the link list is connected to the node at position
    X(1-based index). If the link list does not have any loop, X=0.
    Remove the loop from the linked list, if it is present, 
    i.e. unlink the last node which is forming the loop.
*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL)
            return;
            
        Node* slow = head;
        Node* fast = head;
        
        while(slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            
            if(slow == fast)
                break;
        }
        
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        while(slow->next != fast){
            slow = slow->next;
        }
        slow->next = NULL;
    }
};