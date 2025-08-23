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
 
// root will be passed
void bfs(Node*root){
    if(root==NULL) {
        cout<<"Tree has no Node"<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        Node*curr=q.front();       
        q.pop();
 
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
    cout<<endl;
}
 
int delete_node( Node*root, int key){
     // If the tree is empty
    if (root == NULL)
        return 0;
 
    // If the tree has only one node
    if (root->left == NULL && root->right == NULL) {
 
        // If the root node is the key, delete it
        /*  *** But here is that amazing concept and 
           place for Analytical thinking.... */
        if (root->data == key){
            delete root;  // This will directly delete the memory
            // which is pointed by both this root and the original root...
            // Now, whatever we do in this root cannot change the original root
            // because there is no connection at all between these two now... 
 
            root=NULL;  
            return 1;
            // If we wrote root=NULL; first, then 5 would be printed as usual...
            // because origianl root couldn't change (as this root pointing NULL)
        }
        else return 0;
    }
    queue<Node*>q;
    q.push(root);
    int flag=0;
    Node*curr,*temp=NULL,*parent=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr->data==key){
            flag=1;
           temp=curr;
        }
        if(curr->left!=NULL) {
            parent=curr;
            q.push(curr->left);
        }
        if(curr->right!=NULL) {
            parent=curr;
            q.push(curr->right);
        }
    }
    if(flag==0) return 0;
    else{
       temp->data=curr->data;
        if(parent->left==curr) parent->left=NULL;
        else parent->right=NULL;
        delete curr;
        curr=NULL;
        return 1;
    }
 
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
//    root->right=new Node(6);
//    root->left=new Node(7);
//    root->right->right=new Node(8);
//    root->right->left=new Node(9);
//    root->left->left=new Node(10);
//    root->right->right->left=new Node(6);
//    root->right->right->right=new Node(20);
//    root->left->left->right=new Node(25);
//    pre_order(root);
//    cout<<endl;
   bfs(root);
   if(delete_node(root,5)==1){
        cout<<"successfully deleted"<<endl;
        cout<<"The current elements are:"<<endl;
        bfs(root);
   }
   else cout << "value not found";
 
   return 0;
}