
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    TreeNode * FindTargetAddress(TreeNode * clonedTree,TreeNode * Target)
    {
        if(clonedTree==nullptr)
        {
            return nullptr;
        }
        if(clonedTree->val==Target->val)
        {
            return clonedTree;
        }
        TreeNode *currLeft=FindTargetAddress(clonedTree->left,Target);
        TreeNode *currRight=FindTargetAddress(clonedTree->right,Target);
        if(currLeft!=nullptr)
        {
            return currLeft;
        }
        return currRight;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return FindTargetAddress(cloned,target);
        
    }
};