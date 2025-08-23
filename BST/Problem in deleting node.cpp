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
void insert(Node*root, int val){
    Node*newnode=new Node(val);   
    Node*curr=root;
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
// Deleting a node
void delete_node(Node*root, int key){
    Node*node=search(root,key);
    if(node==NULL) {
        cout<<"No deletion is possible"<<endl;
        return;
    }
    // Case 1: When target node is a leaf node
    /* (We cannot write ---> delete node;, )
       because the pointer from parent to this node 
       will become a dangling pointer then */
 
    /* and also this ---> node=NULL; will not work, becuase 
       node is some pointer that is additionally pointing the target node
       when we are writhing ---> node=NULL; then it points nothing and 
       thus tree remains the same..*/
 
    // This is the main disadvantage of using search function directly...  
    if(node->left==NULL && node->right==NULL) node=NULL;
 
    // Case 2: When node has only children but no grandchild
    else if(node->left->left==NULL || node->right->right==NULL){
        // Must be swapped with right child's value (think it why?)
        // But if the right child is NULL then do swap with left
        if(node->right==NULL){
            node->data=node->left->data;
            node->left=NULL;
        }
        else{
            node->data=node->right->data;
            node->right=NULL;
        }
 
    }
    // Case 3: Something in the middle, (child, grandchild all exist)
 
}
void pre_order(Node*curr){
    if(curr==NULL) return;
    cout<<curr->data<<" ";
    pre_order(curr->left);
    pre_order(curr->right);
}
int main(){
    Node*root=new Node(100);
    insert(root,20);
    insert(root,500);
    insert(root,10);
    insert(root,30);
    delete_node(root,500);
    Node*temp=search(root,500);
    if(temp!=NULL) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    pre_order(root);
    cout<<endl;
}
