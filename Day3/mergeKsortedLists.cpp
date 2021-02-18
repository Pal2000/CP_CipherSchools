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
    Node* head, ;
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


Node* sortlists(Node* a, Node* b){
    Node* res=NULL;
     if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data) {
        res = a;
        res->next = sortlists(a->next, b);
    }
    else {
        res = b;
        res->next = sortlists(a, b->next);
    }
 
    return res;
}



Node* mergeLists(Node* a[], int n){
    
    while(n!=0){
        int i=0, j=n;
       
        while(i<j){
            a[i]=sortlists(a[i], a[j]);
            i++;
            j--;
            if(i>=j)
            n=j;
        }
    }
    return a[0];
}

Node * mergeKLists(Node *arr[], int n)
{
       
       if(n==0 || n==1) return arr[0];
       
       return mergeLists(arr, n-1);
       
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
   
    int n = 4; 
    Node* arr[n];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(6);
    arr[0]->next->next = newNode(9);
    arr[0]->next->next->next = newNode(9);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(7);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(1);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(12);
    arr[2]->next->next->next = newNode(16);
 
    Node* head = mergeKLists(arr,n);
 
    printLL(head);
 
    return 0;
}
