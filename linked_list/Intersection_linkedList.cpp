#include<iostream>
#include<unordered_set>

//https://leetcode.com/problems/intersection-of-two-linked-lists/
class ListNode
{

    public:
        int val;
        ListNode * next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       std::unordered_set<ListNode *> _set;
       while(headA!=nullptr)
       {
        _set.insert(headA);
        headA=headA->next;
       }
       while(headB!=nullptr)
       {
        if(_set.find(headB)!=_set.end())
        {
            return headB;
        }
        headB=headB->next;
       }
       return nullptr;
    }
};