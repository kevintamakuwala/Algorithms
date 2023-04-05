#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
class node
{
public:
    int data;
    node *next;
    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete this->next;
        }
        cout<<"node deleted with value : "<<value<<endl;
    }
};
// display function
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
// node inserting at head
void InsertAtHead(node *&head, int value)
{
    node *temp = new node(value);
    temp->next = head;
    head = temp;
}
// node inserting at tail
void InsertAtTail(node *&tail, int value)
{
    node *temp = new node(value);
    tail->next = temp;
    tail = temp;
}
// node inserting at a given position
void InsertAtPosition(node *&head, node *&tail, int pos, int value)
{
    if (pos == 1)
    {
        InsertAtHead(head, value);
        return;
    }
    int cnt = 1;
    node *temp = head;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // maintaining tail position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, value);
        return;
    }
    // inserting new node (tail position maintained).
    node *NodeToInsert = new node(value);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
// deleting a node at a position
void DeleteAtPosition(node *&head,node *&tail,int pos)
{
    // If previous node not present
    if(pos==1)
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    node *prev=NULL,*curr=head;
    int cnt=1;
    while(cnt<pos)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    // maintaining tail position
    if(curr->next==NULL)
    {
        tail=prev;        
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    return;
}
int main()
{
    node *n1 = new node(50);
    node *head = n1;
    node *tail = n1;
    InsertAtHead(head, 40);
    InsertAtHead(head, 30);
    InsertAtHead(head, 20);
    InsertAtHead(head, 10);
    InsertAtTail(tail, 60);
    InsertAtPosition(head, tail, 7, 69);
    display(head);
    DeleteAtPosition(head,tail,7);
    display(head);

    // cout << head->data << " " << tail->data;
    return 0;
}