// Approach 1
class Solution {
public:
    int treeHeight(TreeNode* root) {
        // base case
        if(!root)
            return -1;

        // recursive case
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(!root)
            return 0;

        // recursive case
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int rootDiameter = treeHeight(root->left) + treeHeight(root->right) + 2;

        return max(leftDiameter, max(rightDiameter, rootDiameter));
    }
};

// Approach 2
class Solution {
public:
    int diameter = 0;
    int depth(TreeNode* root) {
        // base case
        if(!root)
            return 0;

        // recursive case
        int leftDiameter = depth(root->left);
        int rightDiameter = depth(root->right);

        diameter = max(diameter, leftDiameter + rightDiameter);

        return 1 + max(leftDiameter, rightDiameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);

        return diameter;
    }
};