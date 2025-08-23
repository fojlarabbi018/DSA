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
    // This case must be handled, 
    // otherwise garbage value or undefined behaviour will be seen
    // In the below part "curr->left/right" will mean "NULL->left/right" !!
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
 
/* It's not like a 2D vetcor***
   Because it is something like
    5
    7 6
    10 9 8
    25 6 20  
    and yes this can be stored in a 2D vector!!! */
vector<vector<int>> level_order(Node*root){
    if(root==NULL) {
        cout<<"Tree has no node"<<endl;
        return {};
    }
    vector<vector<int>> res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        // Each time empty lvl_arr will be declared...
        vector<int>lvl_arr;
        int curr_size=q.size();
        for(int i=1;i<=curr_size;i++){
            Node*curr=q.front();
            q.pop();
            lvl_arr.push_back(curr->data);
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        res.push_back(lvl_arr);
    }
    return res;
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
   cout<<endl;
   bfs(root);
   vector<vector<int>> res=level_order(root);
   for(int i=0;i<res.size();i++){
    cout<<"[";
    for(int j=0;j<res[i].size();j++){ // Size of the inner vectors will auto.. be tracked
        cout<<res[i][j]<<" ";
    }
    cout<<"]";
   }
   cout<<endl;
   return 0;
}