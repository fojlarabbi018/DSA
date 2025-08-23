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
 
void delete_node(Node*root, int key){
    if(root==NULL) {
        cout<<"No deletion is possible"<<"\n";
        return;
    }
    Node*parent=NULL;
    Node*curr=root;
    while(curr!=NULL){
        // Seaching the node
        if(key<curr->data){
            parent=curr;
            curr=curr->left;
        }
        else if(key>curr->data){
            parent=curr;
            curr=curr->right;
        }
        else{
            // After finding the node
            // Case 1: leaf node
            if(curr->left==NULL && curr->right==NULL){
                // ---> curr=NULL; or delete curr; you cannot do that (think it)
                if(parent->left==curr) {
                    parent->left=NULL;
                    delete curr;
                }
                else {
                    parent->right=NULL;
                    delete curr;
                }
            }
            // Case 2: does not have right child
            // Left child or left grand child... anything
            else if(curr->right==NULL){
                // Just break the connection
                parent->left=curr->left;
                delete curr;
            }
            // The most imp. case
            // Case 3: both the left and right children are present
            // (these children can have their own children)
            // Just need to replace curr with its in order successor
            // Quite easy as it has the right sub-tree
            else{
                Node*curr2=curr->right;
                Node*parent2=curr;
                while(curr2->left!=NULL){
                    parent2=curr2;
                    curr2=curr2->left;
                }
                // While it has no right grand child
                if(parent2==curr) parent2->right=NULL;
                // When successor has right subtree (or child)
                // then need to hold the connection
                else parent2->left=curr2->right;
                curr->data=curr2->data;
                delete curr2;
            }
            return;
        }
 
    }
    cout<<"Not found"<<"\n";
 
}
// So the main idea is to replace the key with its successor 
// and then delete the successor (for internal nodes)
 
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
    delete_node(root,20);
    in_order(root);
 
    /*          20
              /    \
            15      30
           /  \     / \
         10   18  25   40
         /         \   / \
        4          28 35  45   */
}
