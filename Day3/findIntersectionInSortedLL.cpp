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
    Node* head, *head2;
    SLL(){
        this->head=NULL;
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

Node* findIntersectionInSortedLL(Node* head1, Node* head2)
{
    
    Node* res=NULL, *resNext=NULL;
    Node* l1=head1, *l2=head2;
    while(l1 && l2){
        if(l1->data < l2->data){
            l1=l1->next;
        }
        else if(l1->data >l2->data){
            l2=l2->next;
        }
        else{
            if(res==NULL){
                res=l1;
                resNext=res;
            }
            else{
                resNext->next=l1;
                resNext=resNext->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
    }
    return res;
}


   
int main()
{
    SLL* sll=new SLL();
    sll->head = new Node(1);
    sll->head->next = new Node(2);
    sll->head->next->next = new Node(3);
    sll->head->next->next->next = new Node(4);
    sll->head->next->next->next->next = new Node(6); 

    sll->head2 = new Node(0);
    sll->head2->next = new Node(1);
    sll->head2->next->next = new Node(3);
    sll->head2->next->next->next = new Node(4);
    sll->head2->next->next->next->next = new Node(5); 
    sll->head2->next->next->next->next->next = new Node(7);

    NOde* res=findIntersectionInSortedLL(sll->head, sll->head2);
   printLL(res);
   
}




