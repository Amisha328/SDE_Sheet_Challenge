// Tree Traversals

#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
#include<bits/stdc++.h>
using namespace std;
void preInPostTraversal(BinaryTreeNode<int>* root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder) 
{
     stack<pair<BinaryTreeNode<int>*, int>> s;
     s.push({root, 1});
     if(root == NULL) return;
     while(!s.empty())
     {
               auto it = s.top();
               s.pop();
              // this is part of preorder
              // increment 1 to 2 
              // push the left side of the tree
               if(it.second == 1)
               {
                         preorder.push_back(it.first->data);
                         it.second++;
                         s.push(it);
                         if(it.first->left)
                              s.push({it.first->left, 1});
               }
               // this is a part of inorder 
               // increment 2 to 3 
               // push right
               else if(it.second == 2)
               {
                         inorder.push_back(it.first->data);
                         it.second++;
                         s.push(it);
                         if(it.first->right)
                              s.push({it.first->right, 1}); 
               }
              // don't push it back again 
               else
                    postorder.push_back(it.first->data);
     }   
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    preInPostTraversal(root, preorder, inorder, postorder);
    return {inorder, preorder, postorder};
}