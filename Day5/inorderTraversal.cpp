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
    

void inorderTraversal(Node* root){
    if(!root) return;
    preorderTraversal(root->left);
    cout<<root->data<<" ";
    preorderTraversal(root->right);
}



int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
   
   inorderTraversal(root);

  
  
    return 0; 
} 
