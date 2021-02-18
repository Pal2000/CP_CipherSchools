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


  Node *reverseLinkedListInGroups(Node *head, int k)
  {
      if (head == NULL || head->next == NULL)
          return head;
      Node *curr = head, *next = NULL, *prev = NULL;
      int i = 0;
      while (curr != NULL && i < k)
      {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
           i++;
      }
      if (next != NULL)
          head->next = reverseLinkedListInGroups(next, k);
      return prev;
  }
  
  void printLL(Node* head){
    if(head==NULL) 
    return;
    else{
        Node* ptr=head;
        while(ptr){
            cout<<ptr->val<<"  ";
            ptr=ptr->next;
        }
    }
}



int main()
{
    SLL* sll=new SLL();
   sll->head=new Node(0);
   for(int i=0;i<6;i++){
       sll->head=insertAtFront(sll->head, i+1);
   }
  int k=3;
   sll->head=reverseLinkedListInGroups(sll->head,k);
      printLL(sll->head);
   cout<<"\n";
 }
