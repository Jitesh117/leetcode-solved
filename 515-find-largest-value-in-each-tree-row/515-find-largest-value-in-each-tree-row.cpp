/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return{};
        queue<TreeNode*> q;
        q.push(root);
        vector<int>result;
        
        while(q.size())
        {
            int mvalue = INT_MIN;
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->val>mvalue)
                    mvalue=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            result.push_back(mvalue);
        }
        return result;
    }
};