

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
        {
            return true;
        }
        if(p==nullptr || q==nullptr)
        {
            return false;
        }
         if((p->left==nullptr & q->left==nullptr) && (p->right==nullptr && q->right==nullptr) && p->val==q->val)
        {
           return true;
        }
        bool status=true;
        if((p->left!=nullptr && q->left!=nullptr) && (p->right!=nullptr && q->right!=nullptr) && p->val==q->val)
        {
            status=(status & isSameTree(p->left,q->left));
            status=status & isSameTree(p->right,q->right);
            

        }
        else
        if((p->left==nullptr && q->left==nullptr) && (p->right!=nullptr && q->right!=nullptr) && p->val==q->val)
        {
  
            status=status & isSameTree(p->right,q->right);
        }
        else 
        if((p->left!=nullptr && q->left!=nullptr) && (p->right==nullptr && q->right==nullptr) && p->val==q->val)
        {
           
            status=status & isSameTree(p->left,q->left);
        }
        else
        {
            status&=false;
        }
        
       
        
        return status;

        
        
    }
};