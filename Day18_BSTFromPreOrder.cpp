// Approach 1   TC: O(NlogN)

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

// Approach 2  TC: O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int> pre, int& i, int upperBound) {
        if(i == pre.size() || pre[i] > upperBound)
            return NULL;

        TreeNode* root = new TreeNode(pre[i++]);

        root->left = buildTree(pre, i, root->val);
        root->right = buildTree(pre, i, upperBound);

        return root;       
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }
};