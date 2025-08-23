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
 
Node*min(Node*root){
    Node*curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node*get_successor(Node*root, int key){
    if(root==NULL) return NULL;
    Node*curr=root;
    Node*succ=NULL;
    while(curr!=NULL){
        if(key<curr->data){
            succ=curr;
            curr=curr->left;
        }
        else if(key>curr->data){
            // We will not change the succ when traversing to the right
            // because the right child is definitely greater than the curr
            curr=curr->right;
        }
        else{
            if(curr->right!=NULL) return min(curr->right);
            else break; /* The current succ will be returned 
                           because there is no right sub-tree */
        }
 
    }
    return succ;
 
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
    Node*temp=get_successor(root,30);
    cout<<temp->data;
 
    /*          20
              /    \
            15      30
           /  \    /  \
         10    18 25   40
         /         \   / \
        4          28 35  45   */
}
