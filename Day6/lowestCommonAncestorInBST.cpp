#include <bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int data;  
    Node* left, *right;  
};  

Node* newNode(int data)  
{  
    Node* node = new Node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return(node);  
}  

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
      if(!root) return NULL;
      if(root->val < p->data && root->data < q->data )
          return lowestCommonAncestor(root->right, p, q);
      else if(root->data > p->data && root->data > q->data)
          return lowestCommonAncestor(root->left, p, q);
      return root;
 }


int main()  
{ 
    Node *root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    
    Node* res= lowestCommonAncestor(root,root->left->right->left, root->left->right->right);
    cout<<res->data;
    return 0;
}
