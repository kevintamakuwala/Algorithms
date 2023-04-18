/*
    Problem Link: https://leetcode.com/problems/palindrome-linked-list/

    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/

class Solution {
public:    
    bool isPalindrome(ListNode* head) {
        ListNode *mid=midElement(head);
        ListNode *rev=reverseList(mid);
        return compareList(head,rev);
    }
    bool compareList(ListNode *head1,ListNode *head2)
    {
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val!=head2->val)
            {
                return 0;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return 1;
    }
    ListNode *midElement(ListNode *head)
    {
        ListNode *fast=head,*slow=head;
        
        while(fast!=NULL  && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
        
    ListNode *reverseList(ListNode *head)
    {
        ListNode *NextNode=NULL,*prev=NULL,*curr=head;
        while(curr!=NULL)
        {
            NextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=NextNode;
        }
        return prev;
    }
};