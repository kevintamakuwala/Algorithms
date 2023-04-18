/*
    Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/

    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by 
    splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
*/

class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
        
    ListNode *temp,*ans;
    
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    if(l1->val > l2->val)
        swap(l1,l2);
    
    ans=l1;
    
    while(l1!=NULL &&  l2!=NULL)
    {
        temp=NULL;
        
        while(l1!=NULL && l1->val <= l2->val )
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return ans;
}
};