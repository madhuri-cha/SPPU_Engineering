//singly link list
#include<iostream>
using namespace std;
class Node
{   public :
    int val; // define data and address of next node 
    Node *next;

Node(int data) //creation of constructor for passing value
{
    val=data;
    next =NULL;
}
};
void insertAtHead(Node* &head,int val) // insertion
{
 Node *new_node = new Node(val);
 new_node->next = head;
 head = new_node;
}
void insertAtend(Node* &head,int val)
{
 Node *new_node = new Node(val); 
 Node *temp = head; // make a temp node and store value of head in node
 while(temp->next!=NULL)   
{
   temp = temp->next; // traversal of the list for getting last node
}
 temp->next = new_node; //here temp->next stored new_node value
}
void insertAnyNode(Node* &head, int val, int pos)
{
    if(pos==0)
    {
     insertAtHead(head,90);
      
    }
    Node *new_node = new Node(val);
    Node* temp= head;
    int current_pos = 0;
    while(current_pos!=pos-1)
{ 
    temp = temp->next; // traversal
    current_pos++;
}
 //temp pointing to node at pos -1
 new_node->next =temp->next;
 temp->next = new_node;

}
void deleteAtstart(Node* &head)
{
    Node* temp = head;//node to be deleted
    head = head->next;
    free(temp);//free up space which occupy by head
}
  void deleteAtend(Node* &head)
{
    Node *second_last = head;
   
    while(second_last->next->next != NULL)
   {   
    second_last = second_last->next;
    }
    // now second last points to 
    Node* temp = second_last->next; //store second last value in temp for free up the memory
    second_last->next = NULL;
    free(temp);
} 
void deleteAnyNode(Node*  &head,int pos)
{
   if(pos = 0)
   {
     deleteAtstart(head);
     return;
   }
   Node *prev = head;
   Node* temp = prev->next;//Node to be deleted
   int current_pos = 0;
   while(current_pos != pos-1)
   {
       prev = prev->next;
       current_pos++;
   }
   free(temp);
   prev->next = prev->next->next;

}
void display(Node *head)//creation of function
{
    Node *temp = head; //traversal of the link
    while(temp!=NULL)
    {
        cout<<temp->val<<"\t";
        temp  = temp->next;
    }
    cout<<"NULL"<<endl;
}
int reverselist(Node* head)
{
    Node * prevptr = NULL;
    Node * curptr = head;
   while(curptr!=NULL)
   {
    Node *nextptr = curptr->next;
    curptr->next = prevptr;
    prevptr = curptr;
    curptr = prevptr;
    }
   Node* new_head = prevptr;
   cout<<new_head;
}


int main(){
    Node *head = NULL;
    insertAtHead(head,28);
    display(head);
    insertAtHead(head,56);
    display(head);
    insertAtend(head,78);
    display(head);
    insertAnyNode(head,88,1);
    display(head);
    insertAnyNode(head,12,2);
    display(head);
    deleteAtstart(head);
    display(head);
    deleteAtend(head);
    display(head);
    deleteAnyNode(head,3);
    display(head);
    reverselist(head);
    display(head);
    return 0;

}