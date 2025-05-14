//https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#include<iostream>
class ListNode
{

    public:
        int val;
        ListNode * next;
        ListNode(int val)
        {
            this->val=val;
            next=nullptr;
        }
};

void traverse(ListNode * head)
{
    while(head!=nullptr)
    {
        std::cout<<head->val<<std::endl;
        head=head->next;

    }
    
}
int length(ListNode *head)
{
    int cnt=0;
    while(head!=nullptr)
    {
        cnt+=1;
        head=head->next;

    }
    return cnt;
}

ListNode * reverse(ListNode * head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    ListNode * curr=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return curr;
}

ListNode* reverseKGRP(ListNode * head,int k)
{
   
    if(head==nullptr || k==0)
    {
        return head;
    }
    ListNode * temp=new ListNode(-1);
    ListNode * curr=temp;
    ListNode *currHead=head;
   int divisor=length(head)/k;
   for(int i=0;i<divisor;i++)
   {
  
        ListNode * tail=currHead;
        for(int j=0;j<k-1;j++)
        {
            tail=tail->next;

        }
        ListNode * nextHead=tail->next;
        tail->next=nullptr;
        ListNode * reverseHead=reverse(currHead);
        temp->next=reverseHead;
        temp=currHead;
        currHead=nextHead;

   }
   temp->next=currHead;

   return curr->next;
}

int main()
{
    ListNode * head=new ListNode(20);
    head->next=new ListNode(30);
    head->next->next=new ListNode(40);
    head->next->next->next=new ListNode(50);
    head->next->next->next->next=new ListNode(60);
    head->next->next->next->next->next=new ListNode(70);
    
    reverseKGRP(head,3);

   
    return 0;
}