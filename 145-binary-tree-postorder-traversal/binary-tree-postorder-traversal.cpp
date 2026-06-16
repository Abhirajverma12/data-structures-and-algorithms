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
//  Solve the Postorder traveersal by ITERATIVE way without recursion by the help of two stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        
        while(!st1.empty()){
            struct TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL) st1.push(node->left);
            if(node->right!= NULL) st1.push(node->right);
        }
        while(!st2.empty()){
            TreeNode* nodee = st2.top();
            st2.pop();
            ans.push_back(nodee->val);
        }
        return ans;
    }
};