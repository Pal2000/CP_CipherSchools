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
    
int presize=0;
Node* create(vector<int> preorder, vector<int> inorder, int instart, int inend, Node* &head){
    if(instart>inend) return NULL;
    Node* root=new Node(preorder[presize++]);
    if(head==NULL)
        head=root;
    int ind=-1;
    for(int i=0;i<=inend;i++){
        if(root->val==inorder[i]){
            ind=i;
            break;
        }
    }
 
    root->left=create(preorder, inorder, instart, ind-1,head);
    root->right=create(preorder, inorder, ind+1, inend,head);
   
    
    return root;
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    Node* root=NULL;
    create(preorder, inorder, 0, inorder.size()-1, root);
    return root;
}

void preorderTraversal(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
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
    
  vector<int> inorder(8), preorder(8);
  for(int i=0;i<8;i++)
  cin>>inorder[i];
   for(int i=0;i<8;i++)
  cin>>preorder[i];
    
   Node* ans=buildTree(preorder, inorder);
   
   preorderTraversal(ans);

  
  
    return 0; 
} 
