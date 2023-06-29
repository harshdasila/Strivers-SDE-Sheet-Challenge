#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>*buildTree(vector<int>&inorder,int inStart, int inEnd, vector<int>&preorder, int preStart, int preEnd, map<int,int>&mpp)
{
    if(preStart>preEnd || inStart>inEnd) return NULL;
    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int inRoot = mpp[root->data];
    int numsLeft = inRoot-inStart;
    root->left = buildTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,mpp);
    root->right = buildTree(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,mpp);
    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    TreeNode<int>* root = buildTree(inorder,0,inorder.size()-1,preorder,0,preorder.size(),mpp);
    return root;
}