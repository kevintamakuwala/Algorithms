/*
    Problem Link: https://leetcode.com/problems/sort-list/

    Given the head of a linked list, return the list after sorting it in ascending order.
*/
class Solution {
public:
ListNode* sortList(ListNode* head)     
{
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *fast=head,*slow=head,*temp=NULL;
        
        while(fast && fast->next)
        {
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        temp->next=NULL;
        
       return mergeSort(sortList(slow),sortList(head));
}
ListNode *mergeSort(ListNode *l1,ListNode *l2)
{
        ListNode *node=new ListNode(0);
        ListNode *temp=node;
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                temp->next=l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1)
        {
            temp->next=l1;
            l1=l1->next;            
        } 
        if(l2)
        {
            temp->next=l2;
            l2=l2->next;            
        }
        return node->next;
    }
};