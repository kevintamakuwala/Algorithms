#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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
void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void InsertAtHead(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertAtTail(node *&head, node *&tail, int d)
{

    node *temp = new node(d);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }
    if (pos == getLength(head))
    {
        InsertAtTail(head, tail, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    node *NodeToInsert = new node(d);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    NodeToInsert->prev = temp;
    temp->next = NodeToInsert;
    return;
}
// deleting a node at a position
void DeleteAtPosition(node *&head,node *&tail,int pos)
{
    // deleting first node
    if(pos==1)
    {
        node *temp=head;        
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    // deleting last node
    if(pos==getLength(head))
    {        
        node *temp=tail; 
        temp->prev->next=NULL;
        tail=temp->prev;
        temp->prev=NULL;        
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
    curr->next->prev=prev;
    curr->prev=NULL;
    curr->next=NULL;
    delete curr;
    return;
}
int main()
{
    node *n1 = new node(60);
    node *head = n1;
    node *tail = n1;
    InsertAtHead(head, tail, 50);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 30);
    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 10);
    InsertAtTail(head, tail, 70);
    Display(head);
    cout << head->data << " " << tail->data << '\n';
    InsertAtPosition(head, tail, 3, 69);
    Display(head);
    cout << head->data << " " << tail->data << '\n';
    DeleteAtPosition(head,tail,1);
    Display(head);
    cout << head->data << " " << tail->data << '\n';
    DeleteAtPosition(head,tail,3);
    Display(head);
    cout << head->data << " " << tail->data << '\n';
    DeleteAtPosition(head,tail,6);
    Display(head);
    cout << head->data << " " << tail->data << '\n';
    return 0;
}