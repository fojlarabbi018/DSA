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
/* THIS FUNCTION CANNOT HANDLE THE CASE "when root=NULL"
   When the original root is NULL, then passing that root
   cannot make any changes in that main root, (think it)*/
// Only for that, we need to change the return type. Like Node* insert(...)
void insert(Node*root, int val){
    Node*newnode=new Node(val);   
    // if(root==NULL){
    //     root=newnode;
    //     return root;
    // }
    Node*curr=root;
    // Without tracking parent....
    while(1){
        if(val<curr->data) {
            if(curr->left==NULL) {
                curr->left=newnode;
                break;
            }
            else curr=curr->left;
        }
        else {
            if(curr->right==NULL) {
                curr->right=newnode;
                break;
            }
            else curr=curr->right;
        }
 
    }
}
void pre_order(Node*curr){
       if(curr==NULL) return;
       cout<<curr->data<<" ";
       pre_order(curr->left);
       pre_order(curr->right);
}
int main(){
    // If initially root is NULL,
    // then write "root=insert(root,100);"
    Node*root=new Node(100);
    insert(root,20);
    insert(root,500);
    insert(root,10);
    insert(root,30);
    pre_order(root);
}
