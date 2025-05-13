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

/*

https://leetcode.com/problems/rotate-list/
*/
struct ListNode 
{
    int val;
    ListNode * next;
};
class Solution {
public:

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
    int length(ListNode * head)
    {
        int cnt=0;
        while(head!=nullptr)
        {
            head=head->next;
            cnt+=1;

        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
        {
            return head;
        }
        int _length=length(head);
        k=k%_length;
        if(head->next==nullptr || k==0)
        {
            return head;
        }
       ListNode * newHead1=reverse(head);
        
        
        ListNode * prev=newHead1;
        ListNode * curr=newHead1;
        while(k>0)
        {
           prev=curr;
           curr=curr->next;  
           k-=1;
        }
        prev->next=nullptr;

        //reverse list till length k
        ListNode * newR1=reverse(newHead1);

        //reverse the list from k+1 to n nodes
        ListNode * newR2=reverse(curr);


        /*merging the list of two reversed lists*/
        ListNode * newR3=newR1;
        while(newR3->next!=nullptr)
        {
            newR3=newR3->next;

        }
        while(newR2!=nullptr)
        {
            newR3->next=newR2;
            newR2=newR2->next;
            newR3=newR3->next;
        }
        return newR1;


    }
};