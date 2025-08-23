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
    delete_node(root,45);
    Node*temp=search(root,45);
    if(temp!=NULL) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    in_order(root);
    cout<<endl;
}
