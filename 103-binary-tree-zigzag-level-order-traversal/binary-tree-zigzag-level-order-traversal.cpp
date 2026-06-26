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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool ltr_direction = true ; // ltr - left to right 
        while(!q.empty()){
            int size = q.size();
            vector<int>rows(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (ltr_direction)?i:(size-i-1);
                rows[index] = node->val;
                if(node->left ) q.push(node->left);
                if(node->right )q.push(node->right);
            }
            result.push_back(rows);
            // change the direction after traversing 
            ltr_direction = !ltr_direction;
            
        }
    return result;
    }
};