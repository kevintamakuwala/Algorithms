#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
        }
        cout << "node deleted with value : " << value << endl;
    }
};
void InsertNode(node *&tail, int d,int ele)
{
    //empty list
    if(tail==NULL)
    {
        node *NewNode=new node(ele);     
        tail=NewNode;
        NewNode->next=NewNode;
        return;
    }
    else
    {
        node *curr=tail;
        while(curr->data!=d)
        {
            curr=curr->next;
        }
        node *temp =  new node(ele);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void display(node *tail)
{
    node *temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=tail);  
    cout<<'\n';
}
int main()
{
    node *tail=NULL;
    InsertNode(tail,1,1);
    display(tail);
    
    InsertNode(tail,1,2);
    display(tail);

    InsertNode(tail,2,3);
    display(tail);

    InsertNode(tail,3,4);
    display(tail);


    return 0;
}