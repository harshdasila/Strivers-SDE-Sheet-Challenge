#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto it = q.front();
            q.pop();
            BinaryTreeNode<int>* node = it.first;
            int level = it.second;
            ans.push_back(node->val);
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
    }
    return ans;
}