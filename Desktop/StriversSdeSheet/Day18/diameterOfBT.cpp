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
int height(TreeNode<int>*root, int &diameter){
    if(root==NULL) return 0;
    int l = height(root->left,diameter);
    int r = height(root->right,diameter);
    diameter = max(diameter,l+r);
    return 1+max(l,r);

}


int diameterOfBinaryTree(TreeNode<int> *root)
{
	
    int diameter=0;
    height(root,diameter);
    return diameter;
}
