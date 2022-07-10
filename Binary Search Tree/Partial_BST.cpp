// Partial BST

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

#include<bits/stdc++.h>
// Approach 1: Using Inorder Traversal
void inOrderTraversal(BinaryTreeNode<int> *root, vector<int> &inorder){
    if(root == NULL) return;
    inOrderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inOrderTraversal(root->right, inorder);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // inorder traversal of BST is sorted
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    for(int i = 1; i < inorder.size(); i++){
        if(inorder[i] < inorder[i-1]) return false;
    }
    return true;
}


// Approach 2: Space Optimized
bool isValid(BinaryTreeNode<int> *root, int min, int max)
{
        if(!root) return true;
        if(root->data > max || root->data < min)
            return false;
        return (isValid(root->left, min, root->data) && isValid(root->right, root->data, max));
}
bool validateBST(BinaryTreeNode<int> *root){
    return isValid(root, INT_MIN, INT_MAX);
}