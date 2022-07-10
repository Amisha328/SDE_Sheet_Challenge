// Maximum Path Sum Between Two Leaves

#include<bits/stdc++.h>
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int maxSum(TreeNode<int> *node, long long int &sum)
{
        if(node == NULL) return 0;
        long long int leftSum = maxSum(node->left, sum);
        long long int rightSum = maxSum(node->right, sum);
       
        sum = max(sum, leftSum + rightSum + node->val);
        return (node->val + max(leftSum, rightSum));
}
long long int findMaxSumPath(TreeNode<int> *root)
{
        if(!root) return -1;
        if(!root->left || !root->right) return -1;
        long long int sum = 0;
        long long int ans = maxSum(root, sum);
        return sum;
}
