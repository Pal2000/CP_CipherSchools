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
    node->data = data;  
    node->left = node->right = NULL;  
    return(node);  
} 

Node *buildBST(Node* &root, int ele) {
    if(!root)
        return root = newNode(ele);
    
    if(root->data > ele)
        root->left = buildBST(root->left, ele);
    else
        root->right = buildBST(root->right, ele);
    
    return root;
}

Node* bstFromPreorder(int a[], int n) {
    Node *root = NULL;
    
    for(int i=0;i<n;i++)
        buildBST(root, a[i]);
    
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main()  
{ 
    int a[6]={8,5,1,7,10,12};
    
    Node* res= bstFromPreorder(a,6);
    
    inorder(res);
    
    return 0;
}

