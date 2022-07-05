// Bottom View Of Binary Tree

/*************************************************************
 
    Following is the Binary Tree node structure.

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
#include <bits/stdc++.h> 
vector<int> bottomView(BinaryTreeNode<int> * root)
{
        vector<int> ans;
        if(root == NULL) return ans; 
        map<int, int> mp; // line -> node value
        queue<pair<BinaryTreeNode<int>*, int>> q;  // Node,line
        q.push({root, 0});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            BinaryTreeNode<int> *node = temp.first;
            int line = temp.second;
            mp[line] = node->data;
            if(node->left)
                q.push({node->left, line-1});
            if(node->right)
                q.push({node->right, line+1});
        }
        
        for(auto x: mp)
            ans.push_back(x.second);
        
        return ans;
    
}
