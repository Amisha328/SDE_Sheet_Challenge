// Postorder Traversal

#include<bits/stdc++.h>

// Recursive Solution
// TC-> O(n) | SC-> O(height of the tree)

void postorderTraversal(TreeNode *root, vector<int> &postorder){
    if(root == NULL) return;
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    postorderTraversal(root, postorder);
    return postorder;
}

// Iterative  Solution
// TC-> O(n) | SC-> O(n)

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    stack<TreeNode*> s;
    while(!s.empty() || root != NULL){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                postorder.push_back(temp->data);
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
                root = temp;
        }
    }
    return postorder;
}