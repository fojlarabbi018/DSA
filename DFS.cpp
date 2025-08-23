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
 
void pre_order(Node*curr){
       if(curr==NULL) return;
       cout<<curr->data<<" ";
       pre_order(curr->left);
       pre_order(curr->right);
}
int main(){
/*      5
       / \
      7   6
     /   / \
    10  9   8
     \     / \
     25   6   20    */
 
   Node*root=new Node(5);
   root->right=new Node(6);
   root->left=new Node(7);
   root->right->right=new Node(8);
   root->right->left=new Node(9);
   root->left->left=new Node(10);
   root->right->right->left=new Node(6);
   root->right->right->right=new Node(20);
   root->left->left->right=new Node(25);
   pre_order(root);
   return 0;
}
