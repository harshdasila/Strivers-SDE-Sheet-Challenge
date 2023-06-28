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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    bool flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            auto it = q.front();
            q.pop();
            BinaryTreeNode<int>* node = it.first;
            int level = it.second;
            int index = (flag)? i : size-i-1;
            temp[index] = node->data;
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
        for(auto it: temp){
            ans.push_back(it);
        }
        flag = !flag;
    }
    return ans;
}
