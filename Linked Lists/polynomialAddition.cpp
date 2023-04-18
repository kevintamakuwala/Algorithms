/*
    Problem Link: https://practice.geeksforgeeks.org/problems/polynomial-addition/1
    
    Given two polynomial numbers represented by a linked list. 
    The task is to complete the function addPolynomial() that adds these lists 
    meaning adds the coefficients who have the same variable powers.

    Note:  Given polynomials are sorted in decreasing order of power.
*/


class Solution{
    public:
    Node* addPolynomial(Node *p1, Node *p2)
    {
        Node *q1=p1,*q2=p2;
        Node *ans=new Node(-1,-1);
        Node *x=ans;
        while(q1!=NULL && q2!=NULL)
        {
            if(q1->pow == q2->pow)
            {
                q1->coeff=q1->coeff+q2->coeff;
                x->next=q1;
                x=x->next;
                q1=q1->next;
                q2=q2->next;
            }
            else if(q1->pow > q2->pow)
            {
                x->next=q1;
                x=x->next;
                q1=q1->next;
            }
            else if(q2->pow >q1->pow)
            {
                x->next=q2;
                x=x->next;
                q2=q2->next;
            }
        }
        while(q1!=NULL)
        {
                x->next=q1;
                x=x->next;
                q1=q1->next;
        }
        while(q2!=NULL)
        {
                x->next=q2;
                x=x->next;
                q2=q2->next;
        }
        return ans->next;

    }
};
