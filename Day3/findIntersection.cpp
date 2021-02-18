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
    Node* head1, *head2;
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


int helper(Node* head1, Node *head2, int d){
    Node* l=head1, *s=head2;
    while(d>0){
        l=l->next;
        d--;
    }
    while(l && s){
        if(l == s) return l->data;
        l=l->next;
        s=s->next;
    }
    return -1;
}




int countNodes(Node* head) {
     Node *ptr = head;
    int size = 0;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
} 


int findIntersectionLL(Node* head1, Node* head2)
{
     if (head1 == NULL || head2 == NULL)
    {
        return -1;
    }
    
    int n1=countNodes(head1);
    int n2=countNodes(head2);
    
    int d=n1-n2;
    
    if(d==0) return helper(head1, head2, 0);
    else if(d>0) return helper(head1, head2, d);
    else return helper(head2, head1, -1*d);
}






int main()
{
    SLL* sll=new SLL();
    
    sll->head1 = new Node(1);
    sll->head1->next = new Node(2);
    sll->head1->next->next = new Node(4);
    sll->head1->next->next->next = new Node(3);
    sll->head1->next->next->next->next = new Node(6); 

    sll->head2 = new Node(5);
    sll->head2->next = new Node(1);
    sll->head2->next->next = new Node(2);
    sll->head2->next->next->next = new Node(3);
    sll->head2->next->next->next->next = new Node(4); 
    sll->head2->next->next->next->next->next = new Node(7);

    findIntersectionLL(sll->head1, sll->head2);
   
}
