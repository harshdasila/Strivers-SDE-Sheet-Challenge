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

void f(TreeNode<int>*root, vector<int>&ans, int level){
    if(root==NULL) return;
    if(ans.size()==level) {
        ans.push_back(root->data);
    }
    f(root->left,ans,level+1);
    f(root->right,ans,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    f(root,ans,0);
    return ans;
}