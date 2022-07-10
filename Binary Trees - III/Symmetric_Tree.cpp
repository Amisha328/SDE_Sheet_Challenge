// Symmetric Tree

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
#include<bits/stdc++.h>
bool check( BinaryTreeNode<int>* leftSubtree, BinaryTreeNode<int>* rightSubtree)
{
        if(!leftSubtree || !rightSubtree)
            return (leftSubtree == rightSubtree);
        if(leftSubtree->data != rightSubtree->data)
            return false;
        return (check(leftSubtree->left, rightSubtree->right) && check(leftSubtree->right, rightSubtree->left));
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    return (root == NULL || check(root->left, root->right));
}