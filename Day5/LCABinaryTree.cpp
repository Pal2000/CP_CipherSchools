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
    
bool findPath(Node* root, vector<Node*> &p, Node* node){
    if(!root) return false;
    p.push_back(root);
    if(root==node)return true;
    if((root->left && findPath(root->left,p, node)) || (root->right && findPath(root->right,p, node))) 
        return true;
    p.pop_back();
    return false;
        
}

 Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    vector<Node*> p1, p2;
    if(!findPath(root, p1,p) || !findPath(root, p2,q)) return NULL;
    int i;
    for(i=0;i<p1.size()&&i<p2.size();i++){
        if(p1[i]!=p2[i])
            break;
    }
    return p1[i-1];
 }


int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
  
    
   Node* ans=lowestCommonAncestor(root, root->left->left, root->left->right);
   cout<<ans->data;
  
  
    return 0; 
} 
