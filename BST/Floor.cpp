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
 
int floor(Node*root, int key){
    Node*curr=root;
    int floor_val=-1; // According to the statement of the statement
    while(curr!=NULL){
        if(curr->data>key){
            curr=curr->left;
        }
        else{
            // If it's equal or less than, then 
            // at first consider it, then test the right child
            floor_val=curr->data;
            curr=curr->right;
        }
    }
    return floor_val;
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
    cout<<floor(root,11);
 
    /*          20
              /    \
            15      30
           /  \    /  \
          10   18 25   40
         /         \   / \
        4          28 35  45   */
}
