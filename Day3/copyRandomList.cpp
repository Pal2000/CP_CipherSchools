#include <bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int data; 
    Node *next,*random; 
    Node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 
  

void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
} 
  
Node* copyRandomList(Node* head) {
    if(head==NULL) return head;

    Node* ptr=head;
    while(ptr){
        Node* node=new Node(ptr->val);
        Node* t=ptr->next;
        ptr->next=node;
        node->next = t;
        ptr=ptr->next->next;
    }
    ptr=head;
    while( ptr){
        if(ptr->random)
        ptr->next->random=ptr->random->next;

        ptr=ptr->next->next;
    }

    ptr=head;
    Node* head2=head->next;
    Node* clone=head2;
    while(clone->next){
        ptr->next=ptr->next->next;
        clone->next=clone->next->next;
        ptr=ptr->next;
        clone=clone->next;
    }
    ptr->next=NULL;
    return head2;
}

int main() 
{ 
    Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
    start->random = start->next->next; 
    start->next->random = start;  
    start->next->next->random = start->next->next->next->next; 
    start->next->next->next->random = start->next->next->next->next; 
    start->next->next->next->next->random = start->next; 
  
    cout << "Original list : \n"; 
    print(start); 
    cout << "\nCloned list : \n"; 
    Node *cloned_list = copyRandomList(start); 
    print(cloned_list); 
  
    return 0; 
}
