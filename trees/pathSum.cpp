#include<iostream>
/*https://leetcode.com/problems/path-sum/?envType=problem-list-v2&envId=binary-tree*/
class TreeNode 
{

    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val)
    {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution {
public:
    bool PathSum(TreeNode * root,int targetSum,int currSum)
{
    if(root==nullptr)
    {
        return false;
    }
   if(root->left==nullptr && root->right==nullptr && targetSum==currSum+root->val)
   {
        return true;
   }
   
    return PathSum(root->left,targetSum,currSum+root->val) || PathSum(root->right,targetSum,currSum+root->val);

}



    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return false;
        }
    return PathSum(root,targetSum,0);
    }
};



