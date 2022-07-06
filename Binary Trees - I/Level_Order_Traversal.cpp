// Level Order Traversal

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
       vector<int> ans;
       if(root == NULL) return ans;
       queue<BinaryTreeNode<int>*> q;
       q.push(root);
       while(!q.empty())
       {
           BinaryTreeNode<int> *curr = q.front();
           ans.push_back(curr->val);
           q.pop();
           if(curr->left)
            q.push(curr->left);
           if(curr->right)
            q.push(curr->right);
       }
       
       return ans;
}