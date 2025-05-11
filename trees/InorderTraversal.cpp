#include<iostream>
#include<vector> 



//https://leetcode.com/problems/binary-tree-inorder-traversal/?envType=problem-list-v2&envId=tree
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
    void inorderTraversal(TreeNode * root, std::vector<int> & result)
    {
        if(root==nullptr)
        {
            return ;
        }
        inorderTraversal(root->left,result);
        result.emplace_back(root->val);
        inorderTraversal(root->right,result);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {

         std::vector<int> result;
         inorderTraversal(root,result);
         return result;
    }
};