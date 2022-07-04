// Inorder Traversal

#include<bits/stdc++.h>

// Recursive solution
// Time Complexity: O(n)
// Auxiliary Space: O(height of tree)

void inorderTraversal(TreeNode *root, vector<int> &inorder){
    if(root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder); 
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    return inorder;
}


// Iterative solution
// Time Complexity: O(n) : as pushing and poping to a stack requires O(1) time.
// Auxiliary Space: O(n)
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            inorder.push_back(root->val);
            root = root->right;
        }
        return inorder;
}