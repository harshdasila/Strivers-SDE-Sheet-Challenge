/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 
#include<bits/stdc++.h>
TreeNode<int>* buildTree(vector<int>&postorder, int ps, int pe, vector<int>&inorder, int is, int ie, map<int,int>&mpp){
     if(ps>pe || is>ie) return NULL;
     TreeNode<int>* root = new TreeNode<int>(postorder[pe]);
     int inRoot = mpp[postorder[pe]];
     int numLeft = inRoot - is;
     root->left = buildTree(postorder,ps,ps+numLeft-1,inorder,is,inRoot-1,mpp);
     root->right = buildTree(postorder,ps+numLeft,pe-1,inorder,inRoot+1,ie,mpp);
     return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	map<int,int>mpp;
     for(int i=0;i<inOrder.size();i++){
          mpp[inOrder[i]]=i;
     }
     return buildTree(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,mpp);
}
