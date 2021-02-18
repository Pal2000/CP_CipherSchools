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



Node* detectAndremove(Node* head){
    if(!head) return NULL;
    if(head->next==NULL) return NULL;
    Node* slow=head, *fast=head->next->next;
    bool flag=false;
    while(slow && fast && fast->next){
        if(slow==fast) {
            flag=true;
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(flag){
        cout<<"\n yes loop detected!!\n";
        slow=head;
        Node* ptr;
        while(1){
            ptr=fast;
            while(ptr->next != fast && ptr->next != slow){
                ptr=ptr->next;
            }
            if(ptr->next==slow) break;
            slow=slow->next;
        }

        ptr->next=NULL;
    }
    return head;
}





int main()
{
    SLL* sll=new SLL();
    sll->head=new Node(0);
   
    sll->head = new Node(5);
    sll->head->next = new Node(1);
    sll->head->next->next = new Node(2);
    sll->head->next->next->next = new Node(3);
    sll->head->next->next->next->next = new Node(4); 
    
    sll->head->next->next->next->next->next =  sll->head->next;

    sll->head=detectAndremove(sll->head);
    printLL(sll->head);
    cout<<"\n";
    
   
}

