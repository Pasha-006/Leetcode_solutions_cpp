
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

//https://leetcode.com/problems/root-equals-sum-of-children/description/?envType=problem-list-v2&envId=tree
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root->val==(root->left->val+root->right->val))
        {
            return true;
        }
        return false;
        
    }
};