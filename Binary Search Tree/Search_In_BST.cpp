// Search In BST

/*
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
    };
*/

#include<bits/stdc++.h>
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root != NULL)
    {
        if(root->data == x)
            return true;
        else if(root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}