#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node(){
        data=0;
        this->left=NULL;
        this->right=NULL;
    }
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insert(int val, Node* root){
    if(!root)
    return new Node(val);
    if(val<root->data)
    root->left=insert(val, root->left);
    else
    root->right=insert(val, root->right);
    return root;
}

Node* getMax(Node* root){
    if(!root) return NULL;
    while(root->left)
    root=root->left;
    return root;
}

Node* remove(int val,Node* root){
    if(!root) return NULL;
    if(val<root->data)
    root->left = remove(val, root->left);
    else if(val>root->data)
    root->right = remove(val, root->right);
    else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(!root->left){
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(!root->right){
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        Node* temp=getMax(root->left);// preorder predeccessor
        root->data=temp->data;
        root->left=remove(temp->data, root->left);
        
    }
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
    Node* root=NULL;
    root = insert(50, root);
    root = insert(30, root);
    root = insert(20, root);
    root = insert(40, root);
    root = insert(70, root);
    root = insert(60, root);
    root = insert(80, root);

    inorder(root);
    cout<<"\n\n After removal";
    root=remove(70, root);

    inorder(root);

    return 0;

}
