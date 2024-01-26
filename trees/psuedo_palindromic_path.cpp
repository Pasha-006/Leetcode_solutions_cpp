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
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

class Solution {
public:
    void display(map<int,int> &mp)
    {
        auto ptr=mp.begin();
        while(ptr!=mp.end())
        {
            std::cout<<"first value is : "<<ptr->first<<" frequency value is : "<<ptr->second<<std::endl;

            ptr++;
        }
        std::cout<<std::endl;
        
    }
    int traverse(TreeNode *root,map<int,int> &mp)
    {
        if(root==nullptr)
        {
            return 0;
        }
        else
        if((root->left==NULL &&root->right==NULL))
        {   
            //cout<<root->val<<endl; 
            mp[root->val]++;
            int ans=palidrome(mp);
            mp[root->val]--;
            //display(mp);
            return ans;
        }
        mp[root->val]++;
        int ans=traverse(root->left,mp)+traverse(root->right,mp);
        mp[root->val]--;
        return ans;
        
    }
    int palidrome(map<int,int> &mp)
    {
        int uneven=0;
        auto ptr=mp.begin();
        int length=0;
        while(ptr!=mp.end())
        {
            if(ptr->second!=0 && ptr->second%2!=0 )
            {
                uneven+=1;
            }
            length+=ptr->second;

            ptr++;
        }
        if(((uneven==0) && length%2==0)|| (uneven==1 && length%2!=0))
        {
           //std::cout<<"yes palidrome"<<std::endl;
           
            return 1;
        }
        //std::cout<<"No palidrome"<<std::endl;
        return 0;
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {
        map<int,int> mp;
       // mp[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        return traverse(root,mp);

        
    }
};
