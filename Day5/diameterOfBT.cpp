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
    
int maxDepth(Node* node)
{
    if(node==NULL)
        return 0;
    int left=maxDepth(node->left);
    int right=maxDepth(node->right);
    return max(left,right)+1;
}

int diameterOfBinaryTree(Node* root) {
    if(root==NULL)
        return 0;
    int dia=maxDepth(root->left)+maxDepth(root->right);
    return max(dia,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
}

int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
  
    
   cout<<diameterOfBinaryTree(root);

  
  
    return 0; 
} 
