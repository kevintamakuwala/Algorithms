/*
    Problem Link: https://leetcode.com/problems/split-linked-list-in-parts/

    Given the head of a singly linked list and an integer k, split the linked list into k 
    consecutive linked list parts.
    The length of each part should be as equal as possible: no two parts should have a size 
    differing by more than one. This may lead to some parts being null.
    The parts should be in the order of occurrence in the input list,
    and parts occurring earlier should always have a size greater than or equal to 
    parts occurring later.

    Return an array of the k parts.
*/
class Solution 
{
    public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr=head;        
        int len=length(head);
        int x=len%k;        
        vector<ListNode*>v;
        int cnt=len/k,it;
        
        while(curr)
        {
            v.push_back(curr);
            it=1;
            while(it<cnt)
            {
                curr=curr->next;
                it++;
            }
            if(x>0 && len>k)
            {
                curr=curr->next;
                x--;
            }
            
            ListNode *temp=curr->next;
            curr->next=nullptr;
            curr=temp;            
        }
        while(len<k)
        {
            v.push_back(0);
            len++;
        }
        return v;             
    }
    int length(ListNode *head)
    {
        int cnt=0;        
        while(head)
        {
            head=head->next;
            cnt++;
        }
        return cnt;        
    }
};