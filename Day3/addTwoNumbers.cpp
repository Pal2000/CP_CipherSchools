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
    Node *head1, *head2;
    SLL(){
        this->head1=NULL;
        this->head2=NULL;
        
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


Node* addTwoNumbers(Node* l1, Node* l2){
    if(!l1 && !l2) return NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    Node* tmp=NULL, *nexttmp=NULL;
    Node* p1=l1, *p2=l2;
    int carry=0;
    while(p1 && p2){
        int sum=p1->val + p2->val + carry;
        
        if(tmp==NULL){
            tmp=new Node(sum%10);
            nexttmp=tmp;
        } else{
            Node* t=new Node(sum%10);
            nexttmp->next=t;
            nexttmp=nexttmp->next;
        }
        carry=sum/10;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1){
        int sum=p1->val + carry;
        
        if(tmp==NULL){
            tmp=new Node(sum%10);
            nexttmp=tmp;
        } else{
            Node* t=new Node(sum%10);
            nexttmp->next=t;
            nexttmp=nexttmp->next;
        }
        carry=sum/10;
        p1=p1->next;
    }
    while(p2){
        int sum=p2->val + carry;
        
        if(tmp==NULL){
            tmp=new Node(sum%10);
            nexttmp=tmp;
        } else{
            Node* t=new Node(sum%10);
            nexttmp->next=t;
            nexttmp=nexttmp->next;
        }
        carry=sum/10;
        p2=p2->next;
    }

    while(carry >0){
        Node* t=new Node(carry%10);
        nexttmp->next=t;
        nexttmp=nexttmp->next;
        carry=carry/10;
    }
    nexttmp->next=NULL;
    return tmp;
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
  
    sll->head1 = new Node(5);
    sll->head1->next = new Node(6);
    sll->head1->next->next = new Node(3);

    sll->head2 = new Node(8);
    sll->head2->next = new Node(4);
    sll->head2->next->next = new Node(2);

    Node* res = addTwoNumbers(sll->head1, sll->head2);
    printLL(res);
    cout<<"\n";
    
   
}
