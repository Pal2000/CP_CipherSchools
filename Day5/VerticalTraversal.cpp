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

 vector<vector<int>> verticalTraversal(Node* root, vector<vector<int>> &ans) {
  
    if(!root)
        return ans;
    map<int,vector<pair<int,int>>> mp;
    queue<pair<TreeNode*,int>> q;
    
    q.push({root,0});
    mp[0].push_back({0,root->val});
    
    int level=0;
    while(!q.empty()){
        int sz=q.size();
        level++;
        for(int i=0;i<sz;i++)
        {
            Node* cur=q.front().first;
            int hd=q.front().second;
            q.pop();
            if(cur->left)
            {
                mp[hd-1].push_back({level,cur->left->val});
                q.push({cur->left,hd-1});
            }
            if(cur->right)
            {
                mp[hd+1].push_back({level,cur->right->val});
                q.push({cur->right,hd+1});
            }
        }
    }
    for(auto x:mp){
        sort(x.second.begin(), x.second.end());
        vector<int> v;
        for(int i=0;i<x.second.size();i++)
        {
            v.push_back(x.second[i].second);
        }
        ans.push_back(v);
    }
    return ans;
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
   verticalTraversal(root, res);
  
    for(auto x:res)
    {
        for(auto y:x)
        cout<<y<<" ";
        cout<<"\n";
    }
  
    return 0; 
} 
