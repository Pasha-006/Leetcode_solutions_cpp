#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    public:
    class compare 
    {
        public:
        bool operator()(ListNode* ptr,ListNode*ptr2)
        {
            if(ptr!=NULL && ptr2!=NULL)
            {
                if(ptr->val<ptr2->val)
                return true;
                return false;
            }
            else
            if(ptr==NULL)
            {
                return true;
            }
           
            return false;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode *ans=NULL;
       ListNode *temp;
       priority_queue<ListNode*,vector<ListNode*>,compare> pq;
       ListNode *tail;
       for(int i=0;i<lists.size();i++)
       {
           ListNode *temp=lists[i];
           while(temp!=NULL)
           {
               ListNode *t=temp;
               //std::cout<<"Value is "<<temp->val<<std::endl;
               temp=temp->next;
               t->next=NULL;
               if(t!=NULL)
                 pq.push(t);
           }

       }
       while(pq.size()!=0)
       {
          if(ans==NULL)
          {
              ans=pq.top();
              //std::cout<<"value of head node "<<ans->val<<std::endl;
              tail=ans;
          }
          else
          {
              tail->next=pq.top();
              if(pq.top()!=NULL)
              {
              tail=tail->next;
              }
          }
          //std::cout<<"Value is "<<tail->val<<std::endl;
          pq.pop();
       }
       //std::cout<<"value of head node "<<ans->val<<std::endl;
       return ans;
        
    }
};
int main()
{
   int n;
   std::cout<<"How many LinkedList you want : ";
   std::cin>>n;
   std::vector<ListNode *> vect;
   for(int i=0;i<n;i++)
   {
    ListNode *temp=new ListNode(-1);
    ListNode *head=temp; 
        int flag=1;
        do
        {
           std::cout<<"enter value enter :";
           ListNode *t;
           std::cin>>t->val;
           temp->next=t;
           std::cout<<"do want to continue 0.No :";
           std::cin>>flag;
           temp=temp->next;
           
        } while (flag);
        vect.push_back(head->next);
   }

    Solution s;
    ListNode *temp=s.mergeKLists(vect);

         while(temp!=NULL)
        {
            std::cout<<"Value is "<<temp->val<<std::endl;
            temp=temp->next;
        }

    
   





    return 0;
}
