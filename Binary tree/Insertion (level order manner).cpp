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
 
// Inserting Node in "level order manner"
// ( inserting at the first position available in a level order traversing)
void insert_node(Node*root, int key){
    Node*newnode=new Node(key);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*curr=q.front();
        q.pop();
        if(curr->left==NULL) {
            curr->left=newnode;
            break;
        }
        else if(curr->right==NULL) {
            curr->right=newnode;
            break;
        }
        else {
            q.push(curr->left);
            q.push(curr->right);
        }
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
   root->right=new Node(6);
   root->left=new Node(7);
   root->right->right=new Node(8);
   root->right->left=new Node(9);
   root->left->left=new Node(10);
   root->right->right->left=new Node(6);
   root->right->right->right=new Node(20);
   root->left->left->right=new Node(25);
   bfs(root);
   insert_node(root,100);
   bfs(root);
   return 0;
}
