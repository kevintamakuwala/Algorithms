
/*
    Reverse a linked list if its head is given.

    Param: head of a Linked List.
    Returns: head of reversed Linked list.
*/
class Solution{
    public:
    node *reverseLL(node *head)
    {
        node *curr = head, *prev = NULL, next = NULL;
        
        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;

        return head;
    }
}