#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>postorder;
    if(root==NULL) return postorder;
    stack<TreeNode*>st1,st2;        
    st1.push(root);
    while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL){
                st1.push(root->left);
            }
            if (root->right != NULL) {
              st1.push(root->right);
            }
    }
    while(!st2.empty()){
        int d = st2.top()->data;
        st2.pop();
        postorder.push_back(d);
    }
    return postorder;
}