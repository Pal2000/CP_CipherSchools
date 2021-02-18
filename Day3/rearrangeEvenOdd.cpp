#include<bits/stdc++.h>
using namespace std;

// node structure
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
    Node(){
        Node(0);
    }
};

// singly linked list

class SLL{
    public:
    Node* head;
    SLL(){
        this->head=NULL;
        
    }
};


  Node *rearrangeEvenOdd(Node *head)
{
    if(!head || !head->next || !head->next->next) return head;
    Node* odd=head, *even=head->next, *evenfirst=even;
    while(1){
        if(!even || !odd || !even->next){
            odd->next=evenfirst;
            
            break;
        } 
        odd->next=even->next;
        odd=even->next;
        if(odd->next==NULL){
            odd->next=evenfirst;
            even->next=NULL;
            break;
        }
        even->next=odd->next;
        even=odd->next;
    }
    return head;
}

void printLL(Node * head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    SLL* sll=new SLL();
   sll->head=new Node(0);
   for(int i=0;i<6;i++){
       sll->head=insertAtFront(sll->head, i+1);
   }
  
   sll->head=rearrangeEvenOdd(head);
   printLL(sll->head);
   cout<<"\n";
 }
