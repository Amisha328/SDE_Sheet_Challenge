// Top View Of Binary Tree

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
   		vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<TreeNode<int>*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode<int> *node = temp.first;
            int line = temp.second;
            if(mp.find(line) == mp.end())
                mp[line] = node->val;
            if(node->left)
                q.push({node->left, line-1});
            if(node->right)
                q.push({node->right, line+1});
        }
        
        for(auto x: mp)
                ans.push_back(x.second);
                
        return ans;
    }