struct ListNode 
{
    int val;
    ListNode * next;
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode * curr=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return curr;
    }
};