// Check Identical Trees

// Idea:
// Two trees are identical if:
// Preorder/Inorder/Postorder of Tree1 = Preorder/Inorder/Postorder of Tree2

#include <bits/stdc++.h>
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	
    if(root1 == NULL || root2 == NULL)
            return (root1 == root2);
        
    if(root1->data != root2->data)
            return false;
        
    return (identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
}