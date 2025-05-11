struct ListNode 
{
    int val;
    ListNode *next;

};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode * prev=nullptr;
        ListNode * curr=head;
        while(curr->next!=nullptr)
        { 
            ListNode * _next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=_next;    
        }
        curr->next=prev;
        return curr;       
    }
};