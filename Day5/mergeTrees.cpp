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
Node* mergeTrees(Node* t1, Node* t2) {
        if(!t1 && !t2)
            return NULL;
        if(!t1 && t2){
            return t2;
        }
        if(t1 && !t2){
            return t1;
        }
        t1->data=t1->data+t2->data;
        t1->left=mergeTrees(t1->left, t2->left);
        t1->right=mergeTrees(t1->right, t2->right);
        return t1;
    }


void preorder(Node* root){
  if(!root) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
    node *root2 = newNode(10); 
    root2->left = newNode(2); 
    root2->right = newNode(13); 
    root2->left->left = newNode(14); 
    root2->left->right = newNode(25); 
    root2->right->right = newNode(6);
    
   Node* ans=mergeTrees(root, root2);
  
  preorder(ans);
  
  
    return 0; 
} 
