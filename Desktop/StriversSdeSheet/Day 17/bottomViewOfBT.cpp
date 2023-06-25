#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<queue>
vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        root = it.first;
        int level = it.second;
        mpp[level] = root->data;
        if(root->left!=NULL){
            q.push({root->left,level-1});
        }
        if(root->right!=NULL){
            q.push({root->right,level+1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}
