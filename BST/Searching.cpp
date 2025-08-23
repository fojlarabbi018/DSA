#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*left;
    Node*right;
public:
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node* search(Node*root, int key){
    if(root==NULL) return NULL;
    Node*curr=root;
    while(curr!=NULL){
        if(key==curr->data){
            return curr;
        }
        else if(key<curr->data) curr=curr->left;
        else curr=curr->right;
    }
    return NULL;
}
void in_order(Node*curr){
       if(curr==NULL) return;
       in_order(curr->left);
       cout<<curr->data<<" ";
       in_order(curr->right);
}
int main(){
    Node*root=new Node(20);
    root->left=new Node(15);
    root->left->left=new Node(10);
    root->left->right=new Node(18);
    root->left->left->left=new Node(4);
    root->right=new Node(30);
    root->right->right=new Node(40);
    root->right->left=new Node(25);
    root->right->left->right=new Node(28);
    root->right->right->right=new Node(45);
    root->right->right->left=new Node(35);
    in_order(root);
    cout<<endl;
    Node*temp=search(root,10);
    if(temp!=NULL) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
}
 
