https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size=nums1.size()+nums2.size();
        int left1=0;
        int left2=0;
        int median=size/2;
        int prev=0;
        int curr=0;
        int count=0;
        while(left1<nums1.size() && left2<nums2.size() && count<=median)
        {
            if(nums1[left1]<nums2[left2])
            {
                prev=curr;
                curr=nums1[left1++];

            }
            else
            {
                prev=curr;
                curr=nums2[left2++];

            }
            count+=1;
        }
        while(left1<nums1.size() && count<=median)
        {
             prev=curr;
            curr=nums1[left1++];
            count+=1;
        }
         while(left2<nums2.size() && count<=median)
        {
             prev=curr;
            curr=nums2[left2++];
            count+=1;
        }
    
        if(size%2==0)
        {
            return (float(curr)+prev)/2;
        }

        return (float(curr));

    
    }
};
