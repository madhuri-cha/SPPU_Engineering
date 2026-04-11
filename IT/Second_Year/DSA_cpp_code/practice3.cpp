#include<iostream>
using namespace std;
class Node
{   public :
    int val;
    Node *next;
    Node(int data)

    {
        val = data;
        next = NULL;
    }
};
    void insertathead(Node* &head, int val)
    {
        Node* newnode = new Node (val);
        newnode->next = head;
        head = newnode;
    }
    void insertatend(Node* &head,int val)
    {
        Node* newnode = new Node(val);
        Node* temp = head;
        while(temp->next != NULL)
        {
          temp = temp->next;
        }
        temp->next = newnode;

    }
    void insertatpos(Node* &head,int val,int pos)
    { 
        if(pos=0)
        {
            insertathead(head,34);
        }
      Node *prev = head;
      Node *newnode = new Node(val);
      int curr = 0;
      while(curr != pos -1)
      {
        prev = prev->next;
        curr++;
      }
      newnode->next = prev->next;
      prev->next= newnode;

    }
    void deleteheadnode(Node* &head)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    void deleteendnode(Node* &head)
    {
        Node *second_last = head;
        Node* temp;
        while(second_last->next->next !=NULL)
        {
            second_last = second_last->next;
        }
        temp = second_last->next;
        second_last->next=NULL;
        free(temp);
    }
    void deleteanynode(Node* &head,int pos)
    {  if(pos==0)
      {
        deleteheadnode(head);
      }
        Node *prev = head;
        Node *temp;
        int curr = 0;
        while(curr  = pos -1)
        {
            prev = prev->next;
            curr++;
        }
        temp = prev->next;
        prev->next =prev->next->next;
        free(temp);
    } 
    void display(Node* head)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
           cout<<temp->val<<"\t";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

int main() 
{    Node *head = NULL;
     insertathead(head,67);
     display(head);
     insertatend(head,89);
     display(head);
    insertatpos(head,78,2);
    display(head);
     insertatend(head,88);
     display(head);
     insertatend(head,90);
     display(head);
      insertatend(head,99);
     display(head);

      insertatend(head,91);
     display(head);
     insertatend(head,99);
     display(head);
    deleteheadnode(head);
   display(head);
   deleteendnode(head);
   display(head);
   deleteanynode(head,1);
   display(head);
   

 return 0;
}