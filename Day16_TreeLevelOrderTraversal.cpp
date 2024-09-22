class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            vector<int> vec;
            int size = q.size();

            for(int i=0; i<size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front) {
                    vec.push_back(front->val);
                    if(front->left)
                        q.push(front->left);
                    if(front->right)
                        q.push(front->right);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};