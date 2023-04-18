/*
    Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
    
    Given the head of a sorted linked list, delete all duplicates such that each element 
    appears only once. 
    Return the linked list sorted as well.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL )
            return head;
            
        
        while( temp->next!=NULL)
        {
            if(temp->val == temp->next->val)
            {
                temp->next=temp->next->next;
            }
            
            else
                temp=temp->next;
        }
        return head;
    }
};
