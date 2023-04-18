/*
    Problem Link: https://leetcode.com/problems/odd-even-linked-list/

    Given the head of a singly linked list, group all the nodes with odd indices
    together followed by the nodes with even indices, and return the reordered list.
    The first node is considered odd, and the second node is even, and so on.
    Note that the relative order inside both the even and odd groups should remain 
    as it was in the input.
    You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

class Solution {
public:
ListNode* oddEvenList(ListNode* head) {
    
    if(!head || !head->next)
        return head;
    
    ListNode *odd=head,*even=head->next;
    ListNode *tempOdd=odd,*tempEven=even;
    
    while(tempOdd->next && tempEven->next)
    {
        tempOdd->next=tempOdd->next->next;
        tempEven->next=tempEven->next->next;
        
        tempOdd=tempOdd->next;
        tempEven=tempEven->next;
    }
    tempOdd->next=even;

    return head;
}
};