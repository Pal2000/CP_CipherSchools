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




bool palindromicLL(Node* head){
    Node* mid=NULL;
    Node* ptr=head;
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    ptr=head;
    int i=1;
    while(i<=c/2){
        mid=ptr;
        ptr=ptr->next;
        i++;
    }
    Node *half=mid->next;
    half=reverseLLIterative(half);
    Node* n1=head, *n2=half;
    while(n1 && n2){
        if(n1->val !=n2->val) return false;
        n1=n1->next;
        n2=n2->next;
    }
    return true;
}


int main()
{
    SLL* sll=new SLL();
   
    sll->head = new Node(1);
    sll->head->next = new Node(2);
    sll->head->next->next = new Node(3);
    sll->head->next->next->next = new Node(2);
    sll->head->next->next->next->next = new Node(1); 
    

    if(palindromicLL(sll->head2)) cout<<"YES\n";
    else cout<<"NO\n";
    cout<<"\n";
   
}
