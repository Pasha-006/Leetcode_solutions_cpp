#include<iostream>
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
TreeNode* successor(TreeNode * root)
{
    if(root==nullptr || (root->left==nullptr && root->right==nullptr))
    {
        return root;

    }
    return successor(root->left);
}

TreeNode * delNode(TreeNode * root,int key)
{
    if(root->val<key)
    {
        root->right=delNode(root->right,key);
    }
    else
    if(root->val>key)
    {
        root->left=delNode(root->left,key);
    }
    else 
    {
        //when the node dont have the childer or have right child 
        if(root->left==nullptr)
        {
            TreeNode * temp=root->right;
            delete root;
            return temp;
        }
        else 
        if(root->right==nullptr)
        {
            TreeNode *temp=root->left;
            delete root;
            return temp;
        }
        else 
        {
            TreeNode * temp=successor(root->right);
            root->val=temp->val;
            root->right=delNode(root->right,temp->val);
        }



    }
    return root;



}

void traverse(TreeNode * root)
{
    if(root==nullptr)
    {
        return;
    }
    traverse(root->left);
    std::cout<<root->val<<std::endl;
    traverse(root->right);

}

int main()
{
    TreeNode * root=new TreeNode(10);
    root->left=new TreeNode(4);
    root->right=new TreeNode(12);
    root->right->left=new TreeNode(11);
    TreeNode * curr=delNode(root,4);
    
    traverse(curr);
    
    



    return 0;
}