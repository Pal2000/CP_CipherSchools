#include <iostream> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    
}; 

node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
    
void levelorderTraversal(Node* root) {
   
    if(root==NULL)
        return ;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
   
    while(!q.empty()){
        
        Node* cur=q.front();
        q.pop();
       
        cout<<root->data<<" ";
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
         
    }
    return ;
}


int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
   
   levelorderTraversal(root);

  
  
    return 0; 
} 
