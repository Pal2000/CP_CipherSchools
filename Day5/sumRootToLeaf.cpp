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

void solve(Node* root, int num, int &sum)
    {
        if(root==NULL)
            return;
        num=num*10+root->val;
        solve(root->left,num,sum);
        if(!root->left && !root->right)
        sum+=num;
        solve(root->right,num,sum);
    }
    int sumNumbers(Node* root) {
        if(root==NULL)
            return 0;
        int sum=0,num=0;
        solve(root,num,sum);
        return sum;
    }

int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    
   cout<<sumNumbers(root);
  
  
    return 0; 
} 
