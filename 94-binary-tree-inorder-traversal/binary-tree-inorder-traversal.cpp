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
//  flag -- Preorder =1 , Inorder = 2 ,Postorder =3 
    vector<int> PreInPostTraversal(TreeNode * root,int flag){
         if(root == NULL) return {};
        vector<int>In,Pre,Post;
        stack<pair<TreeNode*, int>>st;
        st.push({root,1});

        while(!st.empty()){
            auto it = st.top();
            st.pop();
            TreeNode* node = it.first;
            int num = it.second;

            if(num ==1 ){
                Pre.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->left != NULL ){
                    st.push({node->left,1});
                }
            }
            else if(num ==2){
                In.push_back(node->val);
                num++;
                st.push({node,num});
                if(node->right!= NULL){
                    st.push({node->right,1});
                }
            }
            else {
                Post.push_back(node->val);
                
            }
        }
        if(flag ==1) return Pre;
        if(flag == 2) return In;
        return Post;

    }

    vector<int> inorderTraversal(TreeNode* root) {
       
        vector<int>Inorder = PreInPostTraversal(root,2);
        return Inorder ;
    }
};