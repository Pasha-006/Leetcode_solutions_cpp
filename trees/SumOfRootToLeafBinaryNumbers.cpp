
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr)
        {
            return 1;
        }
        int currLeft= (root->val)<<sumRootToLeaf(root->left);
        int currRight=(root->val)<<sumRootToLeaf(root->right);
        int currSum=
        
    }
};