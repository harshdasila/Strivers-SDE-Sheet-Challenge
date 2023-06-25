/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            root = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mpp[x][y].insert(root->val);
            if(root->left){
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right){
                q.push({root->right,{x+1,y+1}});
            }
        }
        for(auto it: mpp){
            vector<int>col;
            for(auto x: it.second){
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};