// Left View Of a Binary Tree

#include<bits/stdc++.h>

// Recursive
void leftView(TreeNode<int> *root, vector<int> &ans, int level, int &currLevel){
    if(root == NULL) return;
    if(currLevel < level){
        ans.push_back(root->data);
        currLevel = level;
    }
    leftView(root->left, ans, level+1, currLevel);
    leftView(root->right, ans, level+1, currLevel);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
     int currLevel = 0;
     leftView(root, ans, 1, currLevel);
     return ans;
}

// Iterative
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int c = q.size();
        for(int i = 0; i < c; i++)
        {
            TreeNode<int>* curr = q.front();
            q.pop();
            if(i == 0)
                ans.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}