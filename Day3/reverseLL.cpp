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
    Node* head, *head2, *head3, *head4, *head5;
    SLL(){
        this->head=NULL;
    }
};

Node* insertAtFront(Node* head, int data){
    Node* temp=new Node(data);
    if(head==NULL)
    head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data){
    Node*temp=new Node(data);
    if(head==NULL) 
    head=temp;
    else{
        Node* ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}


int getSize(Node* head){
    if(head==NULL) 
    return 0;
    else{
        int c=0;
        Node* ptr=head;
        while(ptr){
            ptr=ptr->next;
            c++;
        }
        return c;
    }
}

Node* reverseLLIterative(Node* head){
    if(!head) return NULL;
    Node* cur=head, *nextnode=NULL, *prev=NULL;
    while(cur){
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    head=prev;
    return head;
}


int main()
{
    SLL* sll=new SLL();
    sll->head=new Node(0);
    for(int i=0;i<6;i++){
        sll->head=insertAtFront(sll->head, i+1);
    }
    
    cout<<getSize(sll->head);
    cout<<"\n";
    
    printLL(sll->head);
    cout<<"\n";
    
    sll->head=reverseLLIterative(sll->head);

    printLL(sll->head);
    cout<<"\n";
   
}
