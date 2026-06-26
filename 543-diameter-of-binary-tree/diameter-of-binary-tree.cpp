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
// optimized O(N) solution .. 
    int maxi = INT_MIN;
    int findheight(TreeNode* root) {
        if(root == NULL ) return 0;

        int lh = findheight(root->left);
        int rh = findheight(root->right);

        return (1 + max(lh,rh));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL) return 0;

        int Lh = findheight(root->left);
        int Rh = findheight(root->right);
        maxi =max(maxi,(Lh+Rh));
        
        if(root->left !=NULL) diameterOfBinaryTree(root->left);
        if(root->right !=NULL)  diameterOfBinaryTree(root->right);

        return maxi;
    }
};