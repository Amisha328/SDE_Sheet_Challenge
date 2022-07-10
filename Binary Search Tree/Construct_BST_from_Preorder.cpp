// Construct BST from Preorder Traversal

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* formBST(vector<int> &pre, int &idx, int bound){
    if(idx == pre.size() || pre[idx] > bound) return NULL;
    TreeNode<int> *root = new TreeNode<int>(pre[idx++]);
    root->left = formBST(pre, idx, root->data);
    root->right = formBST(pre, idx, bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int idx = 0;
    return formBST(preOrder, idx, 1e9+1);
}