#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode<int>*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int level = it.second;
        if(mpp.find(level)==mpp.end()){
            mpp[level] = node->val;
        }
        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}