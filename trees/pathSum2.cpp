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
        void PathSum(TreeNode * root,int targetSum,int currSum,std::vector<int> &path, std::vector<std::vector<int>> &pathList)
{
    if(root==nullptr)
    {
        return ;
    }
   if(root->left==nullptr && root->right==nullptr && targetSum==currSum+root->val)
   {
    path.emplace_back(root->val);
    pathList.emplace_back(path);
    path.pop_back();
       
   }
   path.emplace_back(root->val);
    PathSum(root->left,targetSum,currSum+root->val,path,pathList);
    PathSum(root->right,targetSum,currSum+root->val,path,pathList);
    path.pop_back();

}



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     
        std::vector<std::vector<int>> pathList;
        std::vector<int> path;
        PathSum(root,targetSum,0,path,pathList);
        return pathList;
    }
};