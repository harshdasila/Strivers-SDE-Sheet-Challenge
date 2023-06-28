#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
int check(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    int lh = check(root->left);
    if(lh==-1) return -1;
    int rh = check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    return check(root)!=-1;
}