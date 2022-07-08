// Connect Nodes at Same Level

/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

// TC-> O(N) | SC-> O(N)

#include <bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 1; i <= size; i++){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            if(i != size)
                curr->next = q.front();
            else
                curr->next = NULL;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}