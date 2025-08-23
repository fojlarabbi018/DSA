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
 
// Height or depth of the tree
// Max level will give the height....
int height(Node*root){
    if(root==NULL) {
        cout<<"Tree has no node"<<endl;
        return -1;
    }
    int level=-1;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int curr_size=q.size();
        // It's a nested loop 
        // but here no. of total loop is same for "with for" and "without for"
        for(int i=1;i<=curr_size;i++){ 
            Node*curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        level++; // counting level from 0...
                 // Incrementing "level" after traversing each level(by popping)
    }
    return level; // When no. of edges is considered (same like level)
 
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
 
   cout<<height(root);
   return 0;
}
