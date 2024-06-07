/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {

public:
    int lengthOfLinkedList(ListNode * head)
    {
        int count=0;
        while(head!=NULL)
        {
            count+=1;
            head=head->next;


        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        std::stack<ListNode *> stacks;
        ListNode* tempHead=head;
        ListNode* tail=head;
        int length=lengthOfLinkedList(head);
        int times=length/k;
        int flag=0;
        //std::cout<<times<<std::endl;
        while(times>0)
        {
            for(int i=0;i<k;i++)
            {
                stacks.push(head);
                head=head->next;
            }
            
            if(flag==0)
            {
                flag=1;
                tempHead=stacks.top();
                tail=tempHead;
                tail->next=NULL;
                stacks.pop();
            }
            while(!stacks.empty())
            {
                tail->next=stacks.top();
                tail=tail->next;
                tail->next=NULL;
                stacks.pop();

            }
          
            times-=1;
        }
       
        tail->next=head;
        
        
        return tempHead;

        
    }
};