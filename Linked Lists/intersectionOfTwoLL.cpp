/*
    Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

    Given the heads of two singly linked-lists headA and headB, 
    return the node at which the two lists intersect. 
    If the two linked lists have no intersection at all, return null.
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        
        ListNode *temp1=headA,*temp2=headB;
        
        while(temp1!=temp2)
        {
            if(temp1)
                temp1=temp1->next;
            else
                temp1=headB;
          
            if(temp2)
                temp2=temp2->next;
            else
                temp2=headA;                
        }
        
        return temp1 ;
    }
};