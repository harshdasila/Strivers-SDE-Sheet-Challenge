/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool f(BinaryTreeNode<int>*left, BinaryTreeNode<int>*right){
    if(left==NULL || right==NULL) return left==right;
    if(left->data!=right->data) return false;
    return f(left->left,right->right) && f(left->right,right->left);
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root){
        return true;
    }  
    return f(root->left,root->right);
}