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
    
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> v;
    if(root==NULL)
        return v;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        vector<int> a;
        if(!s1.empty()){
            while(!s1.empty()){
                Node* cur=s1.top();
                a.push_back(cur->data);
                s1.pop();
                if(cur->left)
                    s2.push(cur->left);
                if(cur->right)
                    s2.push(cur->right);
            }
        }
        else if(!s2.empty()){
            while(!s2.empty()){
                Node* cur=s2.top();
                 a.push_back(cur->data);
                s2.pop();
                if(cur->right)
                    s1.push(cur->right);
                if(cur->left)
                    s1.push(cur->left);
            }
        }
        v.push_back(a);
    }
    return v;
}
int main() 
{ 
   node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    
   
   vector<vector<int>> res=zigzagLevelOrder(root);
    for(auto x:res){
        for(auto y:x)
        cout<<y<<" ";
        cout<<"\n";
    }
  
  
    return 0; 
} 
