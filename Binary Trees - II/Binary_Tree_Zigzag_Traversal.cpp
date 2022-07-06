// Binary Tree Zigzag Traversal

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
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(root == NULL) return v;
    stack<BinaryTreeNode<int>*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            // take out a node
            BinaryTreeNode<int> *curr = s1.top();
            s1.pop();
            v.push_back(curr->data);
            // Push children of the taken out node into s2.
            if(curr->left)
                s2.push(curr->left);
            if(curr->right)
                s2.push(curr->right);
        }
        while(!s2.empty()){
            // take out node.
            BinaryTreeNode<int> *curr = s2.top();
            s2.pop();
            v.push_back(curr->data);
            // Push children of the taken out node into s1.
            if(curr->right)
                s1.push(curr->right);
            if(curr->left)
                s1.push(curr->left);
        }
    }
    return v;
}
