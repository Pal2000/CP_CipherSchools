#include<bits/stdc++.h>
using namespace std;

class Node  
{  
    public: 
    int data;  
    Node* left;  
    Node* right;  
};  
  
Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
} 

Node* buildbst(vector<int> nums , int r, int l){
    if(l>r) return NULL;
    
    int mid=(l+r)/2;
    
    Node* root= newNode(nums[mid]);
    
    root->left=buildbst(nums, mid-1, l);
    root->right=buildbst(nums, r, mid+1);
    
    return root;
    
}


void preorder(Node* root, vector<int> &v){
    if(!root) return;
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

vector<int> sortedArrayToBST(vector<int>& nums) {
   
    int n=nums.size();
    Node* root =buildbst(nums, n-1, 0);
    vector<int> v;
    preorder(root,v);
    return v;
}


int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i = 0;i< n; ++i)
  cin >> a[i];
  vector<int> res=sortedArrayToBST(a);
  for(auto x:res)
  cout<<x<<" ";
   return 0;
}
