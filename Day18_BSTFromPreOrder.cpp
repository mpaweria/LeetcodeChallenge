class Solution {
public:
    int i = 0;
    TreeNode* buildTree(vector<int> pre, vector<int> in, int s, int e) {
        if(s > e)
            return NULL;

        int x = pre[i];
        i++;

        TreeNode* root = new TreeNode(x);
        int k;
        for(int j=s; j<=e; j++) {
            if(in[j] == x) {
                k = j;
                break;
            }
        }

        root->left = buildTree(pre, in, s, k-1);
        root->right = buildTree(pre, in, k+1, e);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        return buildTree(preorder, inorder, 0, preorder.size()-1);
    }
};