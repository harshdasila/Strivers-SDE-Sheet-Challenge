#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root){
    if(root->left || root->right){
        return false;
    }
    return true;
}


void addLeftBoundary(TreeNode<int>*root, vector<int>&res){
    TreeNode<int>* node = root->left;
    while(node){
        if(!isLeaf(node)) res.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void addLeafNodes(TreeNode<int>*root, vector<int>&res){
  if (isLeaf(root)) {
    res.push_back(root->data);
    return;
  }
    if(root->left) addLeafNodes(root->left,res);
    
    if(root->right) addLeafNodes(root->right,res);
}

void addRightBoundary(TreeNode<int>*root, vector<int>&res){
    vector<int>temp;
    TreeNode<int>* node = root->right;
    while(node){
        if(!isLeaf(node)) temp.push_back(node->data);
        if(node->right){
            node = node->right;
        }
        else node = node->left;
    }
    for(int i= temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}


vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeafNodes(root,res);
    addRightBoundary(root,res);
    return res;
}