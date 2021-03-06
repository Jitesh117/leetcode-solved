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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(!root) return result;
        
        solve(root,result,to_string(root->val));
        return result;
    }
    void solve(TreeNode* root, vector<string>&result,string temp){
        if(!root->left and !root->right) {
            result.push_back(temp);
            return;
        }
        if(root->left) solve(root->left,result,temp+"->"+to_string(root->left->val));
        if(root->right) solve(root->right,result,temp+"->"+to_string(root->right->val));
            
        }
    };
