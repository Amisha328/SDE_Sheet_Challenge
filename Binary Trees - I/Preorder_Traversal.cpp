// Preorder Traversal
// Root - Left - Right

#include<bits/stdc++.h>

// Recursive Solution
// TC-> O(n) | SC-> O(height of the tree)
    
void preorderTraversal(TreeNode *root, vector<int> &preorder){
    if(root == NULL) return;
    preorder.push_back(root->data);
    preorderTraversal(root->left, preorder);
    preorderTraversal(root->right, preorder);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    preorderTraversal(root, preorder);
    return preorder;
}


// Iterative  Solution
// TC-> O(n) | SC-> O(n)
vector<int> getPreOrderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> s;
        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                preorder.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return preorder;
}
    