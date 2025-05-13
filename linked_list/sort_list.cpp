#include<iostream>
class ListNode
{
    public:
        int val;
        ListNode * next;
        ListNode(int value)
        :val(value)
        {
            next=nullptr;         
        }
    
};


ListNode * merge(ListNode * headA,ListNode * headB)
{
    ListNode * temp=new ListNode(-1);
    ListNode *mergedList=temp;
    while(headA!=nullptr && headB!=nullptr)
    {
        if(headA->val<headB->val)
        {
            temp->next=headA;
            temp=temp->next;
            headA=headA->next;
        }
        else 
        {
            temp->next=headB;
            temp=temp->next;
            headB=headB->next;
        }
    }
    while(headA!=nullptr)
    {
        temp->next=headA;
        headA=headA->next;
        temp=temp->next;
    }
    while(headB!=nullptr)
    {
        temp->next=headB;
        headB=headB->next;
        temp=temp->next;
    }
    return mergedList->next;

}

ListNode * findMid(ListNode * head)
{
    ListNode * slow=head;
    ListNode * fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


ListNode * mergeSort(ListNode * head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }

    ListNode * mid=findMid(head);
    ListNode * temp=mid->next;
    mid->next=nullptr;
    ListNode * sortedList1=mergeSort(head);
    ListNode * sortedList2=mergeSort(temp);
    ListNode * mergedList=merge(sortedList1,sortedList2);
    return mergedList;
    
}
void traverse(ListNode * head)
{
    while(head!=nullptr)
    {
        std::cout<<head->val<<std::endl;
        head=head->next;
    }
}
int main()
{
    ListNode * head=new ListNode(22);
   
    head->next=new ListNode(10);
    head->next->next=new ListNode(20);
     head->next->next->next=new ListNode(8);
    ListNode * sortedNodeHead=mergeSort(head);
    traverse(sortedNodeHead);

    return 0;
}
