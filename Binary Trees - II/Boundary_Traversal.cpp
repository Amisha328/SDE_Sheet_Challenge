// Boundary Traversal of Binary Tree

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// Idea:
// 1) Left Boundary excluding leaf
// 2) Left node in inorder traversal
// 3) Right boundary in reverse(excluding the leaf)
#include <bits/stdc++.h>
bool isLeaf(TreeNode<int>* node)
{
    return (!node->left && !node->right);
}
void leftBoundary(TreeNode<int>* node, vector<int> &res)
{
    TreeNode<int>* curr = node->left;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void rightBoundary(TreeNode<int>* node, vector<int> &res)
{
    TreeNode<int> *curr = node->right;
    stack<int> s;
    while(curr)
    {
        if(!isLeaf(curr)) s.push(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    while(!s.empty())
    {
        res.push_back(s.top());
    	s.pop();
    }
}
void addLeaves(TreeNode<int>* node, vector<int> &res)
{
    if(isLeaf(node))
    {
        res.push_back(node->data);
        return;
    }
    if(node->left) addLeaves(node->left, res);
    if(node->right) addLeaves(node->right, res);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    leftBoundary(root, res);
    addLeaves(root, res);
    rightBoundary(root, res);
    return res;
}