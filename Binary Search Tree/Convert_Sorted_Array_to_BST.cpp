// Convert Sorted Array to BST

/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int> *formBST(vector<int> &pre, int start, int end)
{
        if(start > end) return NULL;
        int mid = (start+end) >> 1;
        TreeNode<int> *root = new TreeNode<int>(pre[mid]);
        
        root->left = formBST(pre, start, mid-1);
        root->right = formBST(pre, mid+1, end);
    
        return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n == 0) return NULL;
    return formBST(arr, 0, n-1);
}