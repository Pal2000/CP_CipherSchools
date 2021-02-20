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
bool solve(TreeNode* root, int sum, int s){
    if(!root)
        return false;
    if((root->left==NULL) && (root->right==NULL))
    {
        s+=root->val;
        if(s==sum)
            return true;
    }
    s+=root->val;
    return (solve(root->left, sum, s) || (solve(root->right, sum, s)));
}
bool hasPathSum(TreeNode* root, int sum) {
    if(!root)
        return false;
   
    return solve(root, sum, 0);
}

int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    vector<vector<int>> res;
   cout<<hasPathSum(root, 12);
  
  
    return 0; 
} 
